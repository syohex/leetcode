#include <cassert>
#include <vector>
#include <string>

std::vector<std::string> splitWordsBySeparator(const std::vector<std::string> &words, char separator) {
    std::vector<std::string> ret;
    std::string tmp;
    for (const auto &word : words) {
        for (char c : word) {
            if (c == separator) {
                if (!tmp.empty()) {
                    ret.push_back(tmp);
                    tmp.clear();
                }
            } else {
                tmp.push_back(c);
            }
        }
        if (!tmp.empty()) {
            ret.push_back(tmp);
            tmp.clear();
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> words{"one.two.three", "four.five", "six"};
        std::vector<std::string> expected{"one", "two", "three", "four", "five", "six"};
        auto ret = splitWordsBySeparator(words, '.');
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"$easy$", "$problem$"};
        std::vector<std::string> expected{"easy", "problem"};
        auto ret = splitWordsBySeparator(words, '$');
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"|||"};
        auto ret = splitWordsBySeparator(words, '|');
        assert(ret.empty());
    }
    return 0;
}
