#include <cassert>
#include <string>
#include <vector>
#include <set>

int countConsistentStrings(const std::string &allowed, const std::vector<std::string> &words) {
    std::set<char> s;
    for (char c : allowed) {
        s.insert(c);
    }

    int ret = 0;
    for (const auto &word : words) {
        bool ok = true;
        for (char c : word) {
            if (s.find(c) == s.end()) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"ad", "bd", "aaab", "baa", "badab"};
        assert(countConsistentStrings("ab", words) == 2);
    }
    {
        std::vector<std::string> words{"a", "b", "c", "ab", "ac", "bc", "abc"};
        assert(countConsistentStrings("abc", words) == 7);
    }
    {
        std::vector<std::string> words{"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
        assert(countConsistentStrings("cad", words) == 4);
    }
    return 0;
}
