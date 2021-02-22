#include <cassert>
#include <vector>
#include <string>

std::string findLongestWord(const std::string &s, const std::vector<std::string> &d) {
    std::string ret;
    for (const auto &word : d) {
        if (word.empty()) {
            continue;
        }

        size_t pos_s = 0;
        size_t pos_w = 0;
        while (pos_s < s.size()) {
            while (pos_s < s.size() && word[pos_w] != s[pos_s]) {
                ++pos_s;
            }

            if (pos_s >= s.size()) {
                break;
            }

            ++pos_w;
            ++pos_s;
        }

        if (pos_w == word.size()) {
            if ((word.size() > ret.size()) || (word.size() == ret.size() && word < ret)) {
                ret = word;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::string str("abpcplea");
        std::vector<std::string> dict{"ale", "apple", "monkey", "plea"};
        auto ret = findLongestWord(str, dict);
        assert(ret == "apple");
    }
    {
        std::string str("abpcplea");
        std::vector<std::string> dict{"a", "b", "c"};
        auto ret = findLongestWord(str, dict);
        assert(ret == "a");
    }
    return 0;
}
