#include <cassert>
#include <string>
#include <algorithm>
#include <cmath>

int equalSubstring(const std::string &s, const std::string &t, int maxCost) {
    int len = s.size();
    int ret = 0;

    int cost = 0;
    int left = 0;
    for (int i = 0; i < len; ++i) {
        cost += std::abs(s[i] - t[i]);
        while (cost > maxCost) {
            cost -= std::abs(s[left] - t[left]);
            ++left;
        }
        ret = std::max(ret, i - left + 1);
    }

    return ret;
}

int main() {
    assert(equalSubstring("abcd", "bcdf", 3) == 3);
    assert(equalSubstring("abcd", "cdef", 3) == 1);
    assert(equalSubstring("abcd", "acde", 0) == 1);
    return 0;
}
