#include <cassert>
#include <vector>
#include <functional>

std::vector<int> eventualSafeNodes(const std::vector<std::vector<int>> &graph) {
    std::function<bool(int node, std::vector<int> &visited, std::vector<int> &checked)> f;
    f = [&](int node, std::vector<int> &visited, std::vector<int> &checked) -> bool {
        if (visited[node]) {
            // find circular
            return true;
        }

        if (checked[node]) {
            return false;
        }

        checked[node] = true;
        visited[node] = true;
        for (int next : graph[node]) {
            if (f(next, visited, checked)) {
                return true;
            }
        }

        visited[node] = false;
        return false;
    };

    int len = graph.size();
    std::vector<int> visited(len, false);
    std::vector<int> checked(len, false);

    std::vector<int> ret;
    for (int i = 0; i < len; ++i) {
        if (!f(i, visited, checked)) {
            ret.push_back(i);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
        std::vector<int> expected{2, 4, 5, 6};
        auto ret = eventualSafeNodes(graph);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> graph{{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
        std::vector<int> expected{4};
        auto ret = eventualSafeNodes(graph);
        assert(ret == expected);
    }
    return 0;
}
