#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

bool makesquare(std::vector<int> &matchsticks) {
    int sum = 0;
    for (int n : matchsticks) {
        sum += n;
    }

    if (sum % 4 != 0) {
        return false;
    }

    int edge = sum / 4;
    int edges[4] = {};
    std::function<bool(size_t pos)> f;
    f = [&f, &matchsticks, &edge, &edges](size_t pos) -> bool {
        if (pos == matchsticks.size()) {
            return edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3] && edges[3] == edges[0];
        }

        for (int i = 0; i < 4; ++i) {
            if (edges[i] + matchsticks[pos] <= edge) {
                edges[i] += matchsticks[pos];
                if (f(pos + 1)) {
                    return true;
                }

                edges[i] -= matchsticks[pos];
            }
        }

        return false;
    };

    std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
    return f(0);
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
    return 0;
}
