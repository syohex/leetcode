#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <limits>

int findTheCity(int n, std::vector<std::vector<int>> &edges, int distanceThreshold) {
    using Data = std::pair<int, int>;
    std::vector<std::vector<std::pair<int, int>>> graph(n, std::vector<Data>{});

    for (const auto &edge : edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }

    int min_cities = n + 1;
    int ret = n + 1;
    for (int i = 0; i < n; ++i) {
        std::priority_queue<Data, std::vector<Data>, std::greater<Data>> q;
        q.push({i, 0});

        std::vector<bool> visited(n, false);
        visited[i] = true;
        std::vector<int> min_weights(n, std::numeric_limits<int>::max());
        min_weights[i] = 0;

        while (!q.empty()) {
            auto [node, current_weight] = q.top();
            q.pop();

            if (current_weight > min_weights[node]) {
                continue;
            }

            for (const auto &[next, weight] : graph[node]) {
                int next_weight = current_weight + weight;
                if (next_weight < min_weights[next]) {
                    min_weights[next] = next_weight;
                    q.push({next, next_weight});
                    visited[next] = true;
                }
            }
        }

        int cities = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && min_weights[j] <= distanceThreshold) {
                ++cities;
            }
        }

        if (cities <= min_cities) {
            ret = i;
            min_cities = cities;
        }
    }

    return ret;
}

int main() {
    {
        int n = 4;
        std::vector<std::vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
        int distanceThreshold = 4;
        int ret = findTheCity(n, edges, distanceThreshold);
        assert(ret == 3);
    }
    {
        int n = 5;
        std::vector<std::vector<int>> edges{{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
        int distanceThreshold = 2;
        int ret = findTheCity(n, edges, distanceThreshold);
        assert(ret == 0);
    }
    {
        int n = 6;
        std::vector<std::vector<int>> edges{{0, 1, 10}, {0, 2, 1}, {2, 3, 1}, {1, 3, 1}, {1, 4, 1}, {4, 5, 10}};
        int distanceThreshold = 20;
        int ret = findTheCity(n, edges, distanceThreshold);
        assert(ret == 5);
    }
    return 0;
}