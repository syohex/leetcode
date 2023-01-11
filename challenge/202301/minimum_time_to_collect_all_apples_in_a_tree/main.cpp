#include <cassert>
#include <vector>
#include <functional>

int minTime(int n, const std::vector<std::vector<int>> &edges, const std::vector<bool> &hasApple) {
    std::function<int(int node, int parent, const std::vector<std::vector<int>> &graph)> f;
    f = [&](int node, int parent, const std::vector<std::vector<int>> &graph) -> int {
        int ret = 0;
        for (int next : graph[node]) {
            if (next == parent) {
                continue;
            }

            int child = f(next, node, graph);
            if (child != 0 || hasApple[next]) {
                ret += child + 2;
            }
        }

        return ret;
    };

    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    return f(0, -1, graph);
}

int main() {
    {
        int n = 7;
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
        std::vector<bool> hasApple{false, false, true, false, true, true, false};
        int ret = minTime(n, edges, hasApple);
        assert(ret == 8);
    }
    {
        int n = 7;
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
        std::vector<bool> hasApple{false, false, true, false, false, true, false};
        int ret = minTime(n, edges, hasApple);
        assert(ret == 6);
    }
    return 0;
}
