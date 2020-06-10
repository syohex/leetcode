#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

int countCharacters(const std::vector<std::string> &words, const std::string &chars) {
    std::map<char, int> charsMap;
    for (char c : chars) {
        ++charsMap[c];
    }

    int ret = 0;
    for (const auto &word : words) {
        auto tmpMap = charsMap;

        bool good = true;
        for (char c : word) {
            if (tmpMap.find(c) == tmpMap.end() || tmpMap[c] <= 0) {
                good = false;
                break;
            }

            --tmpMap[c];
        }

        if (good) {
            ret += static_cast<int>(word.size());
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"cat", "bt", "hat", "tree"};
        std::string chars = "atach";
        assert(countCharacters(words, chars) == 6);
    }
    {
        std::vector<std::string> words{"hello", "world", "leetcode"};
        std::string chars = "welldonehoneyr";
        assert(countCharacters(words, chars) == 10);
    }
    return 0;
}
