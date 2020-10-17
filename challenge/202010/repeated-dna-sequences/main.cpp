#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <cstdio>

std::vector<std::string> findRepeatedDnaSequences(const std::string &s) {
    std::vector<std::string> ret;
    if (s.size() < 10) {
        return ret;
    }

    std::map<std::string, int> m;
    for (size_t i = 10; i <= s.size(); ++i) {
        ++m[s.substr(i - 10, 10)];
    }

    for (const auto &it : m) {
        if (it.second >= 2) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main() {
    {
        std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        auto ret = findRepeatedDnaSequences(s);
        assert((ret == std::vector<std::string>{"AAAAACCCCC", "CCCCCAAAAA"}));
    }
    {
        std::string s = "AAAAAAAAAAAAAAA";
        auto ret = findRepeatedDnaSequences(s);
        assert((ret == std::vector<std::string>{"AAAAAAAAAA"}));
    }
    return 0;
}
