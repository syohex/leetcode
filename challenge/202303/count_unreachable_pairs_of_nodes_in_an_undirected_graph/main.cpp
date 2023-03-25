#include <cassert>
#include <vector>
#include <functional>
#include <queue>
#include <cstdio>

long long countPairs(int n, const std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::function<long long(int node, std::vector<bool> &visited)> f;
    f = [&](int node, std::vector<bool> &visited) -> long long {
        long long nodes = 1;

        std::queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int p = q.front();
            q.pop();

            for (int next : graph[p]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    ++nodes;
                }
            }
        }

        return nodes;
    };

    long long ret = 0;
    long long remains = n;
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            auto nodes = f(i, visited);
            ret += nodes * (remains - nodes);
            remains -= nodes;
        }
    }

    return ret;
}

int main() {
    {
        int n = 3;
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 2}};
        auto ret = countPairs(n, edges);
        assert(ret == 0);
    }
    {
        int n = 7;
        std::vector<std::vector<int>> edges{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
        auto ret = countPairs(n, edges);
        assert(ret == 14);
    }
    return 0;
}
