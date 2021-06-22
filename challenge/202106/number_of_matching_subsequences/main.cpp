#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int numMatchingSubseq(const std::string &s, const std::vector<std::string> &words) {
    int len = s.size();
    std::vector<std::vector<int>> table(26);
    for (int i = 0; i < len; ++i) {
        table[s[i] - 'a'].push_back(i);
    }

    int ret = 0;
    for (const auto &word : words) {
        int index = -1;
        bool ok = true;
        for (char c : word) {
            auto &indexes = table[c - 'a'];
            auto it = std::lower_bound(indexes.begin(), indexes.end(), index);
            if (it == indexes.end()) {
                ok = false;
                break;
            }

            index = *it + 1;
        }

        if (ok) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::string s("abcde");
        std::vector<std::string> words{"a", "bb", "acd", "ace"};
        assert(numMatchingSubseq(s, words) == 3);
    }
    {
        std::string s("dsahjpjauf");
        std::vector<std::string> words{"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
        assert(numMatchingSubseq(s, words) == 2);
    }
    return 0;
}
