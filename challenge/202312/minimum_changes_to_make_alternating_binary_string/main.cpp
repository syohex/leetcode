#include <cassert>
#include <string>
#include <algorithm>

int minOperations(const std::string &s) {
    int zero_start = 0;
    int one_start = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                ++one_start;
            } else {
                ++zero_start;
            }
        } else {
            if (s[i] == '0') {
                ++zero_start;
            } else {
                ++one_start;
            }
        }
    }

    return std::min(zero_start, one_start);
}

int main() {
    assert(minOperations("0100") == 1);
    assert(minOperations("10") == 0);
    assert(minOperations("1111") == 2);
    return 0;
}
