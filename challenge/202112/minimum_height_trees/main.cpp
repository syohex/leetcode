#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <limits>

std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>> &edges) {
    std::map<int, std::vector<int>> graph;
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::function<int(int dist, int p, std::vector<bool> &checked)> f;
    f = [&](int dist, int p, std::vector<bool> &checked) -> int {
        int ret = dist;
        for (const auto &node : graph[p]) {
            if (checked[node]) {
                continue;
            }

            checked[node] = true;
            ret = std::max(ret, f(dist + 1, node, checked));
            checked[node] = false;
        }

        return ret;
    };

    std::map<int, std::vector<int>> m;
    int min_dist = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        std::vector<bool> checked(n, false);
        checked[i] = true;
        int dist = f(1, i, checked);
        min_dist = std::min(min_dist, dist);
        m[dist].push_back(i);
    }

    return m[min_dist];
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