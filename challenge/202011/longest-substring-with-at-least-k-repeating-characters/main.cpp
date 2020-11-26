#include <cassert>
#include <string>
#include <algorithm>

int longestSubstring(const std::string &s, int k) {
    const auto unique_chars = [](const std::string &str) {
        bool arr[26] = {};
        int ret = 0;
        for (const auto c : str) {
            int index = c - 'a';
            if (!arr[index]) {
                ++ret;
                arr[index] = true;
            }
        }

        return ret;
    };

    int ret = 0;
    int limit = static_cast<int>(s.size());
    int uniques = unique_chars(s);
    for (int i = 1; i <= uniques; ++i) {
        int arr[26] = {};

        int start = 0, end = 0;
        int current_uniques = 0;
        int target_uniques = 0;
        while (end < limit) {
            if (current_uniques <= i) {
                int index = s[end] - 'a';
                if (arr[index] == 0) {
                    ++current_uniques;
                }
                ++arr[index];
                if (arr[index] == k) {
                    ++target_uniques;
                }
                ++end;
            } else {
                int index = s[start] - 'a';
                if (arr[index] == k) {
                    --target_uniques;
                }
                --arr[index];
                if (arr[index] == 0) {
                    --current_uniques;
                }
                ++start;
            }

            if (current_uniques == target_uniques) {
                ret = std::max(ret, end - start);
            }
        }
    }

    return ret;
}

int main() {
    assert(longestSubstring("aaabb", 3) == 3);
    assert(longestSubstring("ababbc", 2) == 5);
    assert(longestSubstring("abcdefg", 1) == 7);
    return 0;
}
