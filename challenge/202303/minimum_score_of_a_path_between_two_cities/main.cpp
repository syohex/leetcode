#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

int minScore(int n, const std::vector<std::vector<int>> &roads) {
    std::vector<std::set<std::pair<int, int>>> graph(n + 1);
    int ret = 0;
    for (const auto &road : roads) {
        graph[road[0]].insert({road[1], road[2]});
        graph[road[1]].insert({road[0], road[2]});
        ret = std::max(ret, road[2]);
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<int> q{1};

    while (!q.empty()) {
        int node = q.back();
        q.pop_back();

        visited[node] = true;

        for (const auto &[next, score] : graph[node]) {
            if (visited[next]) {
                continue;
            }

            ret = std::min(ret, score);
            q.push_back(next);
        }
    }

    return ret;
}

int main() {
    {
        int n = 4;
        std::vector<std::vector<int>> roads{{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
        int ret = minScore(n, roads);
        assert(ret == 5);
    }
    {
        int n = 4;
        std::vector<std::vector<int>> roads{{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
        int ret = minScore(n, roads);
        assert(ret == 2);
    }
    return 0;
}
