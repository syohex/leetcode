#include <cassert>
#include <vector>
#include <functional>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>> &graph) {
    std::vector<std::vector<int>> ret;

    std::function<void(size_t p, std::vector<bool> & checked, std::vector<int> & acc)> f;
    f = [&](size_t p, std::vector<bool> &checked, std::vector<int> &acc) {
        if (p == graph.size() - 1) {
            ret.push_back(acc);
            return;
        }

        for (int node : graph[p]) {
            if (!checked[node]) {
                checked[node] = true;
                acc.push_back(node);
                f(node, checked, acc);
                acc.pop_back();
                checked[node] = false;
            }
        }
    };

    std::vector<bool> checked(graph.size(), false);
    std::vector<int> acc{0};
    f(0, checked, acc);
    return ret;
}

void check(const std::vector<std::vector<int>> &got, const std::vector<std::vector<int>> &expected) {
    assert(got.size() == expected.size());

    std::set<std::vector<int>> a(got.begin(), got.end());
    std::set<std::vector<int>> b(expected.begin(), expected.end());
    assert(a == b);
}

int main() {
    {
        std::vector<std::vector<int>> graph{{1, 2}, {3}, {3}, {}};
        std::vector<std::vector<int>> expected{
            {0, 1, 3},
            {0, 2, 3},
        };
        auto ret = allPathsSourceTarget(graph);
        check(ret, expected);
    }
    {
        std::vector<std::vector<int>> graph{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
        std::vector<std::vector<int>> expected{
            {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4},
        };
        auto ret = allPathsSourceTarget(graph);
        check(ret, expected);
    }
    {
        std::vector<std::vector<int>> graph{{1}, {}};
        std::vector<std::vector<int>> expected{{0, 1}};
        auto ret = allPathsSourceTarget(graph);
        check(ret, expected);
    }
    {
        std::vector<std::vector<int>> graph{{1, 2, 3}, {2}, {3}, {}};
        std::vector<std::vector<int>> expected{
            {0, 1, 2, 3},
            {0, 2, 3},
            {0, 3},
        };
        auto ret = allPathsSourceTarget(graph);
        check(ret, expected);
    }
    {
        std::vector<std::vector<int>> graph{{1, 3}, {2}, {3}, {}};
        std::vector<std::vector<int>> expected{
            {0, 1, 2, 3},
            {0, 3},
        };
        auto ret = allPathsSourceTarget(graph);
        check(ret, expected);
    }
    return 0;
}
