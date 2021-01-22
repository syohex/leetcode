#include <cassert>
#include <string>
#include <map>
#include <set>

bool closeStrings(const std::string &word1, const std::string &word2) {
    if (word1.size() != word2.size()) {
        return false;
    }

    std::map<char, int> m1, m2;
    std::set<char> s1, s2;
    for (char c : word1) {
        ++m1[c];
        s1.insert(c);
    }
    for (char c : word2) {
        ++m2[c];
        s2.insert(c);
    }

    if (m1 == m2) {
        return true;
    }

    if (s1 != s2) {
        return false;
    }

    std::map<int, int> mm1, mm2;
    for (const auto &it : m1) {
        ++mm1[it.second];
    }

    for (const auto &it : m2) {
        ++mm2[it.second];
    }

    return mm1 == mm2;
}

int main() {
    assert(closeStrings("abc", "bca"));
    assert(!closeStrings("a", "aa"));
    assert(closeStrings("cabbba", "abbccc"));
    assert(!closeStrings("uau", "ssx"));
    return 0;
}
