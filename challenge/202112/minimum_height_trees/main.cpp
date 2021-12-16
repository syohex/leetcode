#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <limits>

std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>> &edges) {
    if (n <= 2) {
        std::vector<int> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(i);
        }
        return ret;
    }

    std::map<int, std::set<int>> graph;
    for (const auto &edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    std::set<int> leaves;
    for (const auto &it : graph) {
        const auto &nodes = it.second;
        if (nodes.size() == 1) {
            leaves.insert(it.first);
        }
    }

    int left_nodes = n;
    while (left_nodes > 2) {
        left_nodes -= static_cast<int>(leaves.size());

        std::set<int> new_leaves;
        for (int leaf : leaves) {
            for (int node : graph[leaf]) {
                graph[node].erase(leaf);
                if (graph[node].size() == 1) {
                    new_leaves.insert(node);
                }
            }
        }

        leaves = std::move(new_leaves);
    }

    return std::vector<int>(leaves.begin(), leaves.end());
}

int main() {
    {
        std::vector<std::vector<int>> edges{{1, 0}, {1, 2}, {1, 3}};
        std::vector<int> expected{1};
        auto ret = findMinHeightTrees(4, edges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
        std::vector<int> expected{3, 4};
        auto ret = findMinHeightTrees(6, edges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> edges;
        std::vector<int> expected{0};
        auto ret = findMinHeightTrees(1, edges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> edges{{0, 1}};
        std::vector<int> expected{0, 1};
        auto ret = findMinHeightTrees(2, edges);
        assert(ret == expected);
    }
    return 0;
}