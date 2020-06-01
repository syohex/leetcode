#include <cassert>
#include <string>

int lengthOfLongestSubstring(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    int max = 0;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        size_t j;
        for (j = 1; j < s.size(); ++j) {
        }

        size_t length = j - i;
        if (length > max) {
            max = static_cast<int>(length);
        }
    }

    printf("@@ max=%d\n", max);
    return max;
}

int main() {
    assert(lengthOfLongestSubstring("a") == 1);
    assert(lengthOfLongestSubstring("abcde") == 5);
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    // assert(lengthOfLongestSubstring("bbbbbbbb") == 1);
    // assert(lengthOfLongestSubstring("pwwkew") == 3);
    return 0;
}