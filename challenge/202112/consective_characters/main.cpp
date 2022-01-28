#include <cassert>
#include <string>
#include <algorithm>

int maxPower(const std::string &s) {
    int prev = s[0];
    int ret = 1;
    int count = 1;
    int len = s.size();
    for (int i = 1; i < len; ++i) {
        if (prev == s[i]) {
            ++count;
        }
        if (prev != s[i] || i == len - 1) {
            ret = std::max(ret, count);
            count = 1;
            prev = s[i];
        }
    }

    return ret;
}

int main() {
    assert(maxPower("leetcode") == 2);
    assert(maxPower("abbcccddddeeeeedcba") == 5);
    assert(maxPower("triplepillooooow") == 5);
    assert(maxPower("hooraaaaaaaaaaay") == 11);
    assert(maxPower("tourist") == 1);
    assert(maxPower("c") == 1);
    assert(maxPower("cc") == 2);
    return 0;
}
