#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs) {
    std::map<std::vector<int>, std::vector<std::string>> m;
    for (const auto &str : strs) {
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

void check(const std::vector<std::vector<std::string>> &a, const std::vector<std::vector<std::string>> &b) {
    assert(a.size() == b.size());

    std::set<std::set<std::string>> sa, sb;
    for (const auto &v : a) {
        std::set<std::string> tmp;
        for (const auto &str : v) {
            tmp.insert(str);
        }
        sa.insert(tmp);
    }
    for (const auto &v : a) {
        std::set<std::string> tmp;
        for (const auto &str : v) {
            tmp.insert(str);
        }
        sa.insert(tmp);
    }
    for (const auto &v : b) {
        std::set<std::string> tmp;
        for (const auto &str : v) {
            tmp.insert(str);
        }
        sb.insert(tmp);
    }

    assert(sa == sb);
}

int main() {
    {
        std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
        std::vector<std::vector<std::string>> expected{
            {"bat"},
            {"nat", "tan"},
            {"ate", "eat", "tea"},
        };
        auto ret = groupAnagrams(strs);
    }
    return 0;
}
