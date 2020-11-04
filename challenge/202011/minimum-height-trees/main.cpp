#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>> &edges) {
    if (n <= 2) {
        std::vector<int> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(i);
        }

        return ret;
    }

    std::vector<std::set<int>> graph(n);
    for (const auto &edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    std::vector<int> leaves;
    for (size_t i = 0; i < graph.size(); ++i) {
        if (graph[i].size() == 1) {
            leaves.push_back(i);
        }
    }

    int nodes = n;
    while (nodes > 2) {
        nodes -= static_cast<int>(leaves.size());

        std::vector<int> new_leaves;
        for (const auto leaf : leaves) {
            for (auto node : graph[leaf]) {
                graph[node].erase(leaf);
                if (graph[node].size() == 1) {
                    new_leaves.push_back(node);
                }
            }
        }

        leaves = std::move(new_leaves);
    }

    return leaves;
}

int main() {
    {
        std::vector<std::vector<int>> edges{
            {1, 0},
            {1, 2},
            {1, 3},
        };
        auto ret = findMinHeightTrees(4, edges);
        assert((ret == std::vector<int>{1}));
    }
    {
        std::vector<std::vector<int>> edges{
            {3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4},
        };
        auto ret = findMinHeightTrees(6, edges);
        assert((ret == std::vector<int>{3, 4}));
    }
    {
        std::vector<std::vector<int>> edges{};
        auto ret = findMinHeightTrees(1, edges);
        assert((ret == std::vector<int>{0}));
    }
    {
        std::vector<std::vector<int>> edges{
            {0, 1},
        };
        auto ret = findMinHeightTrees(2, edges);
        assert((ret == std::vector<int>{0, 1}));
    }
    return 0;
}
