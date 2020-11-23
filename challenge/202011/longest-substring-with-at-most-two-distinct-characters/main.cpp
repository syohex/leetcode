#include <cassert>
#include <string>
#include <algorithm>

int lengthOfLongestSubstringTwoDistinct(const std::string &s) {
    if (s.size() <= 1) {
        return static_cast<int>(s.size());
    }

    char first_char = s[0], second_char = -1;
    int second_index = -1;

    int max = 0;
    int count = 1;
    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        if (s[i] == first_char) {
            if (second_index != -1 && i > second_index) {
                first_char = second_char;
                second_char = s[i];
                second_index = i;
            }
            ++count;
        } else {
            if (second_char == -1) {
                second_char = s[i];
                second_index = i;
                ++count;
            } else if (s[i] == second_char) {
                ++count;
            } else if (second_char != s[i]) {
                max = std::max(max, count);

                count = i - second_index + 1;

                first_char = second_char;
                second_char = s[i];
                second_index = i;
            }
        }
    }

    return std::max(max, count);
}

int main() {
    assert(lengthOfLongestSubstringTwoDistinct("eceba") == 3);
    assert(lengthOfLongestSubstringTwoDistinct("ccaabbb") == 5);
    assert(lengthOfLongestSubstringTwoDistinct("aaaaa") == 5);
    assert(lengthOfLongestSubstringTwoDistinct("abaccc") == 4);
    assert(lengthOfLongestSubstringTwoDistinct("aac") == 3);
    return 0;
}
