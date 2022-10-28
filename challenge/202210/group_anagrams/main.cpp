#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs) {
    std::map<std::vector<int>, std::vector<std::string>> m;
    for (const std::string &str : strs) {
        std::vector<int> tmp(26, 0);
        for (char c : str) {
            ++tmp[c - 'a'];
        }
        m[tmp].push_back(str);
    }

    std::vector<std::vector<std::string>> ret;
    for (const auto &it : m) {
        ret.push_back(it.second);
    }

    return ret;
}

int main() {
    const auto cmp = [](const std::vector<std::string> &a, const std::vector<std::string> &b) -> bool {
        return a.size() < b.size();
    };

    {
        std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
        std::vector<std::vector<std::string>> expected{
            {"bat"},
            {"tan", "nat"},
            {"eat", "tea", "ate"},
        };
        auto ret = groupAnagrams(strs);
        std::sort(ret.begin(), ret.end(), cmp);
        assert(ret == expected);
    }
    {
        std::vector<std::string> strs{""};
        std::vector<std::vector<std::string>> expected{
            {""},
        };
        auto ret = groupAnagrams(strs);
        std::sort(ret.begin(), ret.end(), cmp);
        assert(ret == expected);
    }
    {
        std::vector<std::string> strs{"a"};
        std::vector<std::vector<std::string>> expected{
            {"a"},
        };
        auto ret = groupAnagrams(strs);
        std::sort(ret.begin(), ret.end(), cmp);
        assert(ret == expected);
    }
    return 0;
}
