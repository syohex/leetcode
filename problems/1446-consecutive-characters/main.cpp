#include <cassert>
#include <string>

int maxPower(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    int ret = 0;
    int maxLen = 1;
    char prev = s[0];
    for (size_t i = 1; i != s.size(); ++i) {
        auto c = s[i];
        if (c == prev) {
            ++maxLen;
        } else {
            if (maxLen > ret) {
                ret = maxLen;
            }
            maxLen = 1;
            prev = c;
        }
    }

    if (maxLen > ret) {
        ret = maxLen;
    }

    return ret;
}

int main() {
    assert(maxPower("leetcode") == 2);
    assert(maxPower("abbcccddddeeeeedcba") == 5);
    assert(maxPower("triplepillooooow") == 5);
    assert(maxPower("hooraaaaaaaaaaa") == 11);
    assert(maxPower("tourist") == 1);
    return 0;
}
