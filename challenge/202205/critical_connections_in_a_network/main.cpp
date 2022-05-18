#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> criticalConnections(int n, const std::vector<std::vector<int>> &connections) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &c : connections) {
        graph[c[0]].push_back(c[1]);
        graph[c[1]].push_back(c[0]);
    }

    std::function<int(int node, int parent, int rank, std::vector<int> &visited, std::vector<std::vector<int>> &ret)> f;
    f = [&f, &graph](int node, int parent, int rank, std::vector<int> &visited, std::vector<std::vector<int>> &ret) -> int {
        if (visited[node] != -1) {
            // detected circulation
            return visited[node];
        }

        visited[node] = rank;

        int min_reachable_rank = rank;
        for (int next : graph[node]) {
            if (next == parent) {
                continue;
            }

            int reachable_rank = f(next, node, rank + 1, visited, ret);
            if (reachable_rank == rank + 1) {
                ret.push_back({node, next});
            }

            min_reachable_rank = std::min(min_reachable_rank, reachable_rank);
        }

        return min_reachable_rank;
    };

    std::vector<int> visited(n, -1);
    std::vector<std::vector<int>> ret;

    (void)f(0, -1, 0, visited, ret);

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> connections{{0, 1}, {1, 2}, {2, 0}, {1, 3}};
        std::vector<std::vector<int>> expected{{1, 3}};
        auto ret = criticalConnections(4, connections);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> connections{{0, 1}};
        std::vector<std::vector<int>> expected{{0, 1}};
        auto ret = criticalConnections(2, connections);
        assert(ret == expected);
    }
    return 0;
}
