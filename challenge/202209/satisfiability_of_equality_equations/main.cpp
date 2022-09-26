#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <functional>

bool equationsPossible(const std::vector<std::string> &equations) {
    std::vector<std::set<int>> graph(26);
    for (const auto &e : equations) {
        if (e[1] == '=') {
            int from = e[0] - 'a';
            int to = e[3] - 'a';

            graph[from].insert(to);
            graph[to].insert(from);
        }
    }

    std::vector<int> colors(26, -1);
    std::function<void(int node, int color)> f;
    f = [&](int node, int color) {
        if (colors[node] == -1) {
            colors[node] = color;

            for (int next : graph[node]) {
                f(next, color);
            }
        }
    };

    for (int i = 0; i < 26; ++i) {
        f(i, i);
    }

    for (const auto &e : equations) {
        if (e[1] == '!') {
            int from = e[0] - 'a';
            int to = e[3] - 'a';

            if (colors[from] == colors[to]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::string> equations{"a==b", "b!=a"};
        bool ret = equationsPossible(equations);
        assert(!ret);
    }
    {
        std::vector<std::string> equations{"a==b", "b==a"};
        bool ret = equationsPossible(equations);
        assert(ret);
    }
    {
        std::vector<std::string> equations{"a==b", "b!=c", "c==a"};
        bool ret = equationsPossible(equations);
        assert(!ret);
    }
    return 0;
}
