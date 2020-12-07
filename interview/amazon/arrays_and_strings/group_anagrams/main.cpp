#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrapms(const std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> ret;
    std::map<std::string, std::vector<std::string>> m;
    for (const auto &str : strs) {
        auto tmp = str;
        std::sort(tmp.begin(), tmp.end());
        m[tmp].push_back(str);
    }

    for (auto &it : m) {
        ret.push_back(std::move(it.second));
    }
    return ret;
}

void check(const std::vector<std::vector<std::string>> &got, const std::vector<std::vector<std::string>> &expected) {
    assert(got.size() == expected.size());

    size_t equal = 0;
    for (const auto &g : got) {
        for (const auto &e : expected) {
            if (g == e) {
                ++equal;
            }
        }
    }

    assert(equal == got.size());
}

int main() {
    {
        std::vector<std::string> strs{"bat", "nat", "tan", "ate", "eat", "tea"};
        std::vector<std::vector<std::string>> expected{
            {"bat"},
            {"nat", "tan"},
            {"ate", "eat", "tea"},
        };
        auto ret = groupAnagrapms(strs);
        check(ret, expected);
    }
    {
        std::vector<std::string> strs{"a"};
        std::vector<std::vector<std::string>> expected{
            {"a"},
        };
        auto ret = groupAnagrapms(strs);
        check(ret, expected);
    }
    {
        std::vector<std::string> strs{""};
        std::vector<std::vector<std::string>> expected{
            {""},
        };
        auto ret = groupAnagrapms(strs);
        check(ret, expected);
    }
    return 0;
}
