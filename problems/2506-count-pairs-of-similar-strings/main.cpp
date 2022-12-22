#include <cassert>
#include <vector>
#include <string>
#include <set>

int similarPairs(const std::vector<std::string> &words) {
    std::vector<std::set<char>> s;
    for (const auto &word : words) {
        s.push_back(std::set<char>(word.begin(), word.end()));
    }

    int ret = 0;
    size_t len = words.size();
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            if (s[i] == s[j]) {
                ret += 1;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"aba", "aabb", "abcd", "bac", "aabc"};
        int ret = similarPairs(words);
        assert(ret == 2);
    }
    {
        std::vector<std::string> words{"aabb", "ab", "ba"};
        int ret = similarPairs(words);
        assert(ret == 3);
    }
    {
        std::vector<std::string> words{"nba", "cba", "dba"};
        int ret = similarPairs(words);
        assert(ret == 0);
    }
    return 0;
}
