#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

int findMaxForm(const std::vector<std::string> &strs, int m, int n) {
    std::vector<std::vector<int>> v(strs.size(), std::vector<int>(2, 0));
    for (size_t i = 0; i < strs.size(); ++i) {
        for (int c : strs[i]) {
            ++v[i][c - '0'];
        }
    }

    std::map<std::vector<int>, int> cache;

    std::function<int(int pos, int count, int zeros, int ones)> f;
    f = [&f, &v, &strs, &m, &n, &cache](int pos, int count, int zeros, int ones) -> int {
        if (pos == strs.size()) {
            return count;
        }

        int ret1 = 0, ret2 = 0;
        if (v[pos][0] + zeros <= m && v[pos][1] + ones <= n) {
            std::vector<int> key{pos + 1, count + 1, zeros + v[pos][0], ones + v[pos][1]};
            if (cache.find(key) == cache.end()) {
                ret1 = f(pos + 1, count + 1, zeros + v[pos][0], ones + v[pos][1]);
                cache[key] = ret1;
            } else {
                ret1 = cache[key];
            }
        }

        if (zeros <= m && ones <= n) {
            std::vector<int> key{pos + 1, count, zeros, ones};
            if (cache.find(key) == cache.end()) {
                ret2 = f(pos + 1, count, zeros, ones);
            } else {
                ret2 = cache[key];
                cache[key] = ret2;
            }
        }

        return std::max(ret1, ret2);
    };

    return f(0, 0, 0, 0);
}

int main() {
    {
        std::vector<std::string> strs{"10", "0001", "111001", "1", "0"};
        assert(findMaxForm(strs, 5, 3) == 4);
    }
    {
        std::vector<std::string> strs{"10", "1", "0"};
        assert(findMaxForm(strs, 1, 1) == 2);
    }
    return 0;
}
