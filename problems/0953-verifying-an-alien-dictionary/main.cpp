#include <cassert>
#include <vector>
#include <string>
#include <map>

bool isAlienSorted(const std::vector<std::string> &words, const std::string &order) {
    std::map<char, int> dict;
    for (int i = 0; i < static_cast<int>(order.size()); ++i) {
        dict[order[i]] = i;
    }

    for (size_t i = 0; i < words.size() - 1; ++i) {
        const auto &word1 = words[i];
        const auto &word2 = words[i + 1];

        size_t j = 0;
        while (true) {
            int v1 = dict[word1[j]], v2 = dict[word2[j]];
            if (v1 < v2) {
                break;
            }
            if (v1 > v2) {
                return false;
            }

            ++j;

            if (j >= word1.size() || j >= word2.size()) {
                if (word1.size() > word2.size()) {
                    return false;
                }
                break;
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::string> input{"hello", "leetcode"};
        std::string order = "hlabcdefgijkmnopqrstuvwxyz";
        assert(isAlienSorted(input, order));
    }
    {
        std::vector<std::string> input{"word", "world", "row"};
        std::string order = "worldabcefghijkmnpqstuvxyz";
        assert(!isAlienSorted(input, order));
    }
    {
        std::vector<std::string> input{"apple", "app"};
        std::string order = "abcdefghijklmnopqrstuvwxyz";
        assert(!isAlienSorted(input, order));
    }
    return 0;
}
