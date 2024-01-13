#include <cassert>
#include <string>
#include <algorithm>

int minSteps(const std::string &s, const std::string &t) {
    int a[26] = {};

    for (size_t i = 0; i < s.size(); ++i) {
        ++a[t[i] - 'a'];
        --a[s[i] - 'a'];
    }

    int ret = 0;
    for (size_t i = 0; i < 26; ++i) {
        ret += std::max(0, a[i]);
    }

    return ret;
}

int main() {
    assert(minSteps("bab", "aba") == 1);
    assert(minSteps("leetcode", "practice") == 5);
    assert(minSteps("anagram", "mangaar") == 0);
    return 0;
}
