#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>

bool makesquare(std::vector<int> &matchsticks) {
    std::function<bool(size_t pos, std::vector<int> & edges, int edge_len, const std::vector<int> &matchsticks)> f;
    f = [&f](size_t pos, std::vector<int> &edges, int edge_len, const std::vector<int> &matchsticks) -> bool {
        if (pos == matchsticks.size()) {
            return edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3];
        }

        for (int i = 0; i < 4; ++i) {
            if (edges[i] + matchsticks[pos] <= edge_len) {
                edges[i] += matchsticks[pos];
                if (f(pos + 1, edges, edge_len, matchsticks)) {
                    return true;
                }
                edges[i] -= matchsticks[pos];
            }
        }

        return false;
    };

    int sum = 0;
    for (int a : matchsticks) {
        sum += a;
    }

    if (sum % 4 != 0) {
        return false;
    }

    std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());

    std::vector<int> edges(4, 0);
    return f(0, edges, sum / 4, matchsticks);
}

int main() {
    {
        std::vector<int> matchsticks{1, 1, 2, 2, 2};
        assert(makesquare(matchsticks));
    }
    {
        std::vector<int> matchsticks{3, 3, 3, 3, 4};
        assert(!makesquare(matchsticks));
    }
    {
        std::vector<int> matchsticks{19, 6, 13, 3, 3, 2, 18, 17, 20, 20, 14, 10, 3, 18, 9};
        assert(!makesquare(matchsticks));
    }
    {
        std::vector<int> matchsticks{4, 13, 1, 1, 14, 15, 1, 3, 13, 1, 3, 5, 2, 8, 12};
        assert(!makesquare(matchsticks));
    }

    return 0;
}