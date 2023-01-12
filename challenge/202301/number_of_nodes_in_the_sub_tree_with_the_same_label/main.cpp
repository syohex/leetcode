#include <cassert>
#include <vector>
#include <functional>
#include <string>

std::vector<int> countSubTrees(int n, const std::vector<std::vector<int>> &edges, const std::string &labels) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::function<std::vector<int>(int node, int parent, std::vector<int> &ret)> f;
    f = [&](int node, int parent, std::vector<int> &ret) -> std::vector<int> {
        std::vector<int> count(26, 0);
        for (int next : graph[node]) {
            if (next == parent) {
                continue;
            }

            auto tmp = f(next, node, ret);
            for (size_t i = 0; i < 26; ++i) {
                count[i] += tmp[i];
            }
        }

        size_t index = labels[node] - 'a';
        count[index] += 1;
        ret[node] = count[index];
        return count;
    };

    std::vector<int> ret(n, 0);
    (void)f(0, -1, ret);
    return ret;
}

int main() {
    {
        int n = 7;
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
        std::string labels("abaedcd");
        std::vector<int> expected{2, 1, 1, 1, 1, 1, 1};

        auto ret = countSubTrees(n, edges, labels);
        assert(ret == expected);
    }
    {
        int n = 4;
        std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 3}};
        std::string labels("bbbb");
        std::vector<int> expected{4, 2, 1, 1};

        auto ret = countSubTrees(n, edges, labels);
        assert(ret == expected);
    }
    {
        int n = 5;
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 3}, {0, 4}};
        std::string labels("aabab");
        std::vector<int> expected{3, 2, 1, 1, 1};

        auto ret = countSubTrees(n, edges, labels);
        assert(ret == expected);
    }
    return 0;
}
