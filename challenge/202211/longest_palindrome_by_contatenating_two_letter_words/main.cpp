#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int longestPalindrome(const std::vector<std::string> &words) {
    std::map<std::string, size_t> m;
    for (const auto &word : words) {
        ++m[word];
    }

    int ret = 0;
    bool has_duplicated = false;
    std::string rev(2, 0);

    for (const auto &[word, count] : m) {
        rev[0] = word[1];
        rev[1] = word[0];

        if (word[0] == word[1]) {
            if (count % 2 == 0) {
                ret += count;
            } else {
                ret += count - 1;
                has_duplicated = true;
            }
        } else if (word[0] < word[1] && m.count({word[1], word[0]}) > 0) {
            ret += 2 * std::min(count, m[rev]);
        }
    }

    if (has_duplicated) {
        ret += 1;
    }

    return 2 * ret;
}

int main() {
    {
        std::vector<std::string> words{"lc", "cl", "gg"};
        int ret = longestPalindrome(words);
        assert(ret == 6);
    }
    {
        std::vector<std::string> words{"ab", "ty", "yt", "lc", "cl", "ab"};
        int ret = longestPalindrome(words);
        assert(ret == 8);
    }
    {
        std::vector<std::string> words{"cc", "ll", "xx"};
        int ret = longestPalindrome(words);
        assert(ret == 2);
    }
    {
        std::vector<std::string> words{"ll", "lb", "bb", "bx", "xx", "lx", "xx", "lx", "ll", "xb",
                                       "bx", "lb", "bb", "lb", "bl", "bb", "bx", "xl", "lb", "xx"};
        int ret = longestPalindrome(words);
        assert(ret == 26);
    }
    {
        std::vector<std::string> words{"em", "pe", "mp", "ee", "pp", "me", "ep", "em", "em", "me"};
        int ret = longestPalindrome(words);
        assert(ret == 14);
    }

    return 0;
}