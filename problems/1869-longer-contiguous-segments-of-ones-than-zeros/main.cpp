#include <cassert>
#include <string>
#include <algorithm>

bool checkZeroOnes(const std::string &s) {
    int max_ones = 0;
    int max_zeros = 0;
    int tmp = 1;
    char prev = s[0];

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == prev) {
            ++tmp;
        } else {
            if (prev == '0') {
                max_zeros = std::max(max_zeros, tmp);
            } else {
                max_ones = std::max(max_ones, tmp);
            }

            tmp = 1;
            prev = s[i];
        }
    }

    if (prev == '0') {
        max_zeros = std::max(max_zeros, tmp);
    } else {
        max_ones = std::max(max_ones, tmp);
    }
    return max_ones > max_zeros;
}

int main() {
    assert(checkZeroOnes("1"));
    assert(!checkZeroOnes("0"));
    assert(!checkZeroOnes("111000"));
    assert(!checkZeroOnes("110100010"));
    assert(checkZeroOnes("0001111"));
    assert(!checkZeroOnes("000111"));
    return 0;
}
