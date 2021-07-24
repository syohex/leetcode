#include <cassert>
#include <string>
#include <vector>
#include <sstream>

std::string reverseWords(const std::string &s) {
    std::vector<std::string> v;
    std::stringstream ss(s);
    std::string tmp;
    while (std::getline(ss, tmp, ' ')) {
        if (tmp.empty()) {
            continue;
        }
        v.push_back(tmp);
    }

    std::string ret;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        ret += *it;
        if (it + 1 != v.rend()) {
            ret += " ";
        }
    }

    return ret;
}

int main() {
    {
        std::string s("the sky is blue");
        std::string expected("blue is sky the");
        auto ret = reverseWords(s);
        assert(ret == expected);
    }
    {
        std::string s(" hello world  ");
        std::string expected("world hello");
        auto ret = reverseWords(s);
        assert(ret == expected);
    }
    {
        std::string s("a good   example");
        std::string expected("example good a");
        auto ret = reverseWords(s);
        assert(ret == expected);
    }
    {
        std::string s("  Bob     Loves Alice   ");
        std::string expected("Alice Loves Bob");
        auto ret = reverseWords(s);
        assert(ret == expected);
    }
    {
        std::string s("Alice does not even like bob");
        std::string expected("bob like even not does Alice");
        auto ret = reverseWords(s);
        assert(ret == expected);
    }
    return 0;
}