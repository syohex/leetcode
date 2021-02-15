#include <cassert>
#include <string>
#include <algorithm>

int minOperations(const std::string &s) {
    int c0 = 0, c1 = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                ++c1;
            } else {
                ++c0;
            }
        } else {
            if (s[i] == '0') {
                ++c0;
            } else {
                ++c1;
            }
        }
    }

    return std::min(c0, c1);
}

int main() {
    assert(minOperations("0100") == 1);
    assert(minOperations("10") == 0);
    assert(minOperations("1111") == 2);
    return 0;
}
