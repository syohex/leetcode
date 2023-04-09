#include <cassert>
#include <string>
#include <algorithm>

int findTheLongestBalancedSubstring(const std::string &s) {
    int len = s.size();
    int zeros = 0;
    int ones = 0;

    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0') {
            if (zeros > 0 && ones > 0) {
                ret = std::max(ret, std::min(zeros, ones) * 2);
                zeros = 0;
            }

            zeros += 1;
            ones = 0;
        } else {
            ones += 1;
        }
    }

    if (zeros > 0 && ones > 0) {
        ret = std::max(ret, std::min(zeros, ones) * 2);
    }

    return ret;
}

int main() {
    assert(findTheLongestBalancedSubstring("01000111") == 6);
    assert(findTheLongestBalancedSubstring("00011111") == 6);
    assert(findTheLongestBalancedSubstring("0001110011") == 6);
    assert(findTheLongestBalancedSubstring("00111") == 4);
    assert(findTheLongestBalancedSubstring("111") == 0);
    return 0;
}
