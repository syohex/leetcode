#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

std::vector<std::string> removeAnagrams(const std::vector<std::string> &words) {
    std::map<char, int> prev;
    std::vector<std::string> ret;
    for (const auto &word : words) {
        std::map<char, int> tmp;
        for (char c : word) {
            ++tmp[c];
        }

        if (prev == tmp) {
            continue;
        }

        prev = std::move(tmp);
        ret.push_back(word);
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"abba", "baba", "bbaa", "cd", "cd"};
        std::vector<std::string> expected{"abba", "cd"};
        auto ret = removeAnagrams(words);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"a", "b", "c", "d", "e"};
        std::vector<std::string> expected{"a", "b", "c", "d", "e"};
        auto ret = removeAnagrams(words);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"a", "b", "a"};
        std::vector<std::string> expected{"a", "b", "a"};
        auto ret = removeAnagrams(words);
        assert(ret == expected);
    }
    return 0;
}
