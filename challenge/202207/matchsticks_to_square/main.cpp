#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <cstdio>

bool makesquare(const std::vector<int> &matchsticks) {
    std::function<bool(size_t pos, int len, int count, int edge_len, std::map<int, int> &m)> f;
    f = [&](size_t pos, int len, int count, int edge_len, std::map<int, int> &m) -> bool {
        if (pos == 4) {
            return count == matchsticks.size();
        }

        int rest = edge_len - len;
        for (const auto &it : m) {
            if (it.second == 0) {
                continue;
            }

            if (it.first > rest) {
                break;
            }

            --m[it.first];
            if (it.first + len == edge_len) {
                if (f(pos + 1, 0, count + 1, edge_len, m)) {
                    return true;
                }
            } else {
                if (f(pos, len + it.first, count + 1, edge_len, m)) {
                    return true;
                }
            }
            ++m[it.first];
        }

        return false;
    };

    std::map<int, int> m;
    int sum = 0;
    for (int a : matchsticks) {
        ++m[a];
        sum += a;
    }

    if (sum % 4 != 0) {
        return false;
    }

    return f(0, 0, 0, sum / 4, m);
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