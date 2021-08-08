#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

bool isPrefixString(const std::string &s, const std::vector<std::string> &words) {
    size_t pos = 0;
    for (const auto &word : words) {
        if (pos + word.size() > s.size()) {
            return false;
        }

        if (!std::equal(word.begin(), word.end(), s.begin() + pos)) {
            return false;
        }

        pos += word.size();
        if (pos >= s.size()) {
            break;
        }
    }

    return pos == s.size();
}

int main() {
    {
        std::string s("iloveleetcode");
        std::vector<std::string> words{"i", "love", "leetcode", "apples"};
        assert(isPrefixString(s, words));
    }
    {
        std::string s("iloveleetcode");
        std::vector<std::string> words{"apples", "i", "love", "leetcode"};
        assert(!isPrefixString(s, words));
    }
    {
        std::string s("ccccccccc");
        std::vector<std::string> words{"c", "cc"};
        assert(!isPrefixString(s, words));
    }
    {
        std::string s("fjasdklfajkl");
        std::vector<std::string> words{"fjas", "dk", "applebanana", "d", "z", "lfaj", "kl", "ajks", "fd"};
        assert(!isPrefixString(s, words));
    }

    return 0;
}