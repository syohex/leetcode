#include <cassert>
#include <string>
#include <algorithm>

int maxScore(const std::string &s) {
    int len = s.size();
    int left = s[0] == '0' ? 1 : 0;
    int right = 0;
    for (int i = 1; i < len; ++i) {
        if (s[i] == '1') {
            ++right;
        }
    }

    int ret = left + right;
    for (int i = 1; i < len - 1; ++i) {
        left += s[i] == '0' ? 1 : 0;
        right -= s[i] == '1' ? 1 : 0;

        ret = std::max(ret, left + right);
    }

    return ret;
}

int main() {
    assert(maxScore("011101") == 5);
    assert(maxScore("00111") == 5);
    assert(maxScore("1111") == 3);
    return 0;
}
