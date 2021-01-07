#include <cassert>
#include <vector>
#include <string>

int lengthOfLongestSubstring(const std::string &s) {
    int ret = 0;
    int start = 0;
    int limit = s.size();
    std::vector<int> table(128, -1);
    for (int i = 0; i < limit; ++i) {
        char c = s[i];
        int prev = table[c];
        int count = 0;
        for (int j = 0; j < 128; ++j) {
            if (prev > table[j]) {
                table[j] = -1;
                ++count;
            }
        }

        if (count == 0) {
            ret = std::max(ret, i - start + 1);
        } else {
            start = prev + 1;
        }

        table[c] = i;
    }

    return ret;
}

int main() {
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbbbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("") == 0);
    return 0;
}
