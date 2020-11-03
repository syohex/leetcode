#include <cassert>
#include <string>
#include <cstdio>

int maxPower(const std::string &s) {
    int count = 1;
    int max = 1;
    char c = s[0];
    for (size_t i = 1; i < s.size(); ++i) {
        if (c == s[i]) {
            ++count;
        } else {
            if (max < count) {
                max = count;
            }
            count = 1;
            c = s[i];
        }
    }

    if (max < count) {
        max = count;
    }

    return max;
}

int main() {
    assert(maxPower("leetcode") == 2);
    assert(maxPower("abbcccddddeeeeedcba") == 5);
    assert(maxPower("triplepillooooow") == 5);
    assert(maxPower("hooraaaaaaaaaaay") == 11);
    assert(maxPower("tourist") == 1);
    assert(maxPower("aaaaaaaaaa") == 10);
    return 0;
}
