#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int lengthOfLongestSubstring(const std::string &s) {
    std::vector<int> table(256, -1);
    int i = 0;
    int ret = 0;
    int length = 0;
    int limit = static_cast<int>(s.size());
    while (i < limit) {
        auto c = static_cast<int>(s[i]);
        if (table[c] == -1) {
            table[c] = i;
            ++length;
            ++i;
            continue;
        }

        ret = std::max(ret, length);
        length = i - table[c];
        for (size_t j = 0; j < 256; ++j) {
            if (table[j] < table[c]) {
                table[j] = -1;
            }
        }
        table[c] = i;
        ++i;
    }

    return std::max(ret, length);
}

int main() {
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring("abba") == 2);
    return 0;
}
