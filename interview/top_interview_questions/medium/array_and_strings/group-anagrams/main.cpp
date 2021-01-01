#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs) {
    std::map<std::map<char, int>, std::vector<std::string>> mm;
    for (const auto &s : strs) {
        std::map<char, int> m;
        for (char c : s) {
            ++m[c];
        }

        mm[m].push_back(s);
    }

    std::vector<std::vector<std::string>> ret;
    for (const auto &it : mm) {
        ret.push_back(it.second);
    }

    return ret;
}

template <typename T>
bool check(const T &got, const T &expected) {
    std::set<std::vector<std::string>> a, b;
    for (const auto &v : got) {
        a.insert(v);
    }
    for (const auto &v : expected) {
        b.insert(v);
    }

    return a == b;
}

int main() {
    {
        std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
        std::vector<std::vector<std::string>> expected{
            {"bat"},
            {"tan", "nat"},
            {"eat", "tea", "ate"},
        };
        auto ret = groupAnagrams(input);
        assert(check(ret, expected));
    }
    {
        std::vector<std::string> input{""};
        std::vector<std::vector<std::string>> expected{
            {""},
        };
        auto ret = groupAnagrams(input);
        assert(check(ret, expected));
    }
    {
        std::vector<std::string> input{"a"};
        std::vector<std::vector<std::string>> expected{
            {"a"},
        };
        auto ret = groupAnagrams(input);
        assert(check(ret, expected));
    }
    return 0;
}
