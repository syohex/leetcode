#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool isAlienSorted(std::vector<std::string> &words, const std::string &order) {
    std::map<char, int> table;
    {
        int i = 0;
        for (char c : order) {
            table[c] = i++;
        }
    }

    const auto cmp = [&table](const std::string &a, const std::string &b) {
        size_t len = std::min(a.size(), b.size());
        for (size_t i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                return table[a[i]] < table[b[i]];
            }
        }

        return a.size() < b.size();
    };

    auto orig = words;
    std::sort(words.begin(), words.end(), cmp);

    return orig == words;
}

int main() {
    {
        std::vector<std::string> words{"hello", "leetcode"};
        std::string order("hlabcdefgijkmnopqrstuvwxyz");
        assert(isAlienSorted(words, order));
    }
    {
        std::vector<std::string> words{"word", "world", "row"};
        std::string order("worldabcefghijkmnpqstuvxyz");
        assert(!isAlienSorted(words, order));
    }
    {
        std::vector<std::string> words{"apple", "app"};
        std::string order("abcdefghijklmnopqrstuvwxyz");
        assert(!isAlienSorted(words, order));
    }
    return 0;
}
