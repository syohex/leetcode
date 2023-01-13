#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

int longestPath(const std::vector<int> &parent, const std::string &s) {
    std::vector<std::vector<int>> graph(parent.size());
    for (size_t i = 1; i < parent.size(); ++i) {
        graph[parent[i]].push_back(i);
    }

    std::function<int(int node, int &ret)> f;
    f = [&](int node, int &ret) -> int {
        int first = 0;
        int second = 0;

        for (int next : graph[node]) {
            int child_max = f(next, ret);
            if (s[node] == s[next]) {
                continue;
            }

            if (child_max > first) {
                second = first;
                first = child_max;
            } else if (child_max > second) {
                second = child_max;
            }
        }

        ret = std::max(ret, first + second + 1);
        return first + 1;
    };

    int ret = 0;
    (void)f(0, ret);
    return ret;
}

int main() {
    {
        std::vector<int> parent{-1, 0, 0, 1, 1, 2};
        std::string s("abacbe");
        int ret = longestPath(parent, s);
        assert(ret == 3);
    }
    {
        std::vector<int> parent{-1, 0, 0, 0};
        std::string s("aabc");
        int ret = longestPath(parent, s);
        assert(ret == 3);
    }
    return 0;
}
