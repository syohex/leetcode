#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

std::vector<int> findRedundantConnection(const std::vector<std::vector<int>> &edges) {
    int n = 0;
    for (const auto &edge : edges) {
        n = std::max(n, edge[1]);
    }

    std::vector<std::vector<int>> graph(n);
    std::function<bool(int start, int target, std::vector<bool> &checked)> f;
    f = [&f, &graph](int start, int target, std::vector<bool> &checked) -> bool {
        if (checked[start - 1]) {
            return false;
        }

        if (start == target) {
            return true;
        }

        checked[start - 1] = true;
        for (int next : graph[start - 1]) {
            if (f(next, target, checked)) {
                return true;
            }
        }

        return false;
    };

    for (const auto &edge : edges) {
        auto &a_nodes = graph[edge[0] - 1];
        auto &b_nodes = graph[edge[1] - 1];
        if (!a_nodes.empty() && !b_nodes.empty()) {
            std::vector<bool> checked(n, false);

            if (f(edge[0], edge[1], checked)) {
                return edge;
            }
        }

        a_nodes.push_back(edge[1]);
        b_nodes.push_back(edge[0]);
    }

    // never happen
    return {};
}

int main() {
    {
        std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};
        std::vector<int> expected{2, 3};
        auto ret = findRedundantConnection(edges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> edges{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
        std::vector<int> expected{1, 4};
        auto ret = findRedundantConnection(edges);
        assert(ret == expected);
    }
    return 0;
}
