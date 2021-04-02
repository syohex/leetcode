#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int findMaxForm(const std::vector<std::string> &strs, int m, int n) {
    std::vector<std::vector<int>> v(strs.size(), std::vector<int>(2, 0));
    for (size_t i = 0; i < strs.size(); ++i) {
        for (int c : strs[i]) {
            ++v[i][c - '0'];
        }
    }

    int ret = 0;
    std::function<void(size_t pos, int count, int zeros, int ones)> f;
    f = [&f, &v, &strs, &ret, &m, &n](size_t pos, int count, int zeros, int ones) {
        ret = std::max(ret, count);
        if (pos == strs.size()) {
            return;
        }

        if (v[pos][0] + zeros <= m && v[pos][1] + ones <= n) {
            f(pos + 1, count + 1, zeros + v[pos][0], ones + v[pos][1]);
        }

        if (zeros <= m && ones <= n) {
            f(pos + 1, count, zeros, ones);
        }
    };

    f(0, 0, 0, 0);
    return ret;
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
