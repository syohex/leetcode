#include <cassert>
#include <string>

int countKConstraintSubstrings(const std::string &s, int k) {
    int len = s.size();
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        int zeros = 0;
        int ones = 0;
        for (int j = i; j < len; ++j) {
            if (s[j] == '0') {
                ++zeros;
            } else {
                ++ones;
            }

            if (zeros > k && ones > k) {
                break;
            }

            ++ret;
        }
    }
    return ret;
}

int main() {
    assert(countKConstraintSubstrings("10101", 1) == 12);
    assert(countKConstraintSubstrings("1010101", 2) == 25);
    assert(countKConstraintSubstrings("11111", 1) == 15);
    return 0;
}
