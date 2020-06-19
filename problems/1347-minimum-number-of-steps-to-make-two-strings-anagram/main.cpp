#include <cassert>
#include <string>
#include <map>

int minSteps(const std::string &s, const std::string &t) {
    if (s == t) {
        return 0;
    }

    std::map<char, int> sm, tm;
    for (size_t i = 0; i < s.size(); ++i) {
        ++sm[s[i]];
        ++tm[t[i]];
    }

    for (const auto &it : sm) {
        if (tm.find(it.first) == tm.end()) {
            tm[it.first] = 0;
        }
    }

    int needChange = 0;
    for (const auto &it : tm) {
        if (sm.find(it.first) == sm.end()) {
            needChange += it.second;
            continue;
        }

        if (it.second == sm[it.first]) {
            continue;
        }

        if (it.second < sm[it.first]) {
            continue;
        }

        needChange += it.second - sm[it.first];
    }

    return needChange;
}

int main() {
    assert(minSteps("abc", "def") == 3);
    assert(minSteps("aaa", "def") == 3);
    assert(minSteps("abc", "abd") == 1);
    assert(minSteps("bab", "aba") == 1);
    assert(minSteps("aaab", "bbba") == 2);
    assert(minSteps("leetcode", "practice") == 5);
    assert(minSteps("anagram", "mangaar") == 0);
    assert(minSteps("xxyyzz", "xxyyzz") == 0);
    assert(minSteps("friend", "family") == 4);
    assert(minSteps("gctcxyuluxjuxnsvmomavutrrfb", "qijrjrhqqjxjtprybrzpyfyqtzf") == 18);
    return 0;
}
