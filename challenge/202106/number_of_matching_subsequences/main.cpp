#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <utility>

int numMatchingSubseq(const std::string &s, const std::vector<std::string> &words) {
    int len = s.size();
    std::map<char, int> table;
    for (int i = 0; i < len; ++i) {
        if (table.find(s[i]) == table.end()) {
            table[s[i]] = i;
        }
    }

    std::vector<std::map<char, int>> v;
    for (int i = 0; i < len - 1; ++i) {
        std::map<char, int> m;
        for (int j = i + 1; j < len; ++j) {
            if (m.find(s[j]) == m.end()) {
                m[s[j]] = j;
            }
        }
        v.push_back(m);
    }

    int ret = 0;
    for (const auto &word : words) {
        auto it = table.find(word[0]);
        if (it == table.end()) {
            continue;
        }

        bool ok = true;
        int index = it->second;
        for (size_t i = 1; i < word.size(); ++i) {
            auto &d = v[index];
            auto it2 = d.find(word[i]);
            if (it2 == d.end()) {
                ok = false;
                break;
            }

            index = it2->second;
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
