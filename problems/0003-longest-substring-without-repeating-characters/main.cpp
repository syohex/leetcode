#include <cassert>
#include <string>
#include <map>
#include <vector>

int lengthOfLongestSubstring(const std::string &s) {
    if (s.empty()) {
        return 0;
    }
    if (s.size() == 1) {
        return 1;
    }

    std::map<char, std::vector<size_t>> m;
    size_t limit = s.size();
    for (size_t i = 0; i < limit; ++i) {
        m[s[i]].push_back(i);
    }

    int substr_len = limit >= 255 ? 255 : limit;
    int max = 0;
    while (substr_len > 0) {
        for (size_t i = 0; i + substr_len <= s.size(); ++i) {
            for (size_t j = i; j < i + substr_len - 1; ++j) {
                const auto &indexes = m[s[j]];
                for (const auto index : indexes) {
                    if (index <= j) {
                        continue;
                    }
                    if (index < i + substr_len) {
                        goto next_substr;
                    }
                }
            }

            goto expand;

        next_substr:;
        }

        substr_len = (max + substr_len) / 2;
        if (max == substr_len) {
            return max;
        }
        continue;

    expand:;
        max = substr_len;
        substr_len = (max + limit) / 2;
        if (max == substr_len) {
            return max;
        }
    }

    return 1;
}

int main() {
    assert(lengthOfLongestSubstring("a") == 1);
    assert(lengthOfLongestSubstring("abcde") == 5);
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    return 0;
}