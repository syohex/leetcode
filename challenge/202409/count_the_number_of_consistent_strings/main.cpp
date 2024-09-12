#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int countConsistentStrings(const std::string &allowed, const std::vector<std::string> &words) {
    std::vector<int> v(26, 0);
    for (char c : allowed) {
        ++v[c - 'a'];
    }

    int ret = 0;
    for (const auto &word : words) {
        if (std::all_of(word.begin(), word.end(), [&v](int c) { return v[c - 'a'] > 0; })) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> words{"ad", "bd", "aaab", "baa", "badab"};
        int ret = countConsistentStrings("ab", words);
        assert(ret == 2);
    }
    {
        std::vector<std::string> words{"a", "b", "c", "ab", "ac", "bc", "abc"};
        int ret = countConsistentStrings("abc", words);
        assert(ret == 7);
    }
    {
        std::vector<std::string> words{"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
        int ret = countConsistentStrings("cad", words);
        assert(ret == 4);
    }
    return 0;
}
