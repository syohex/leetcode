#include <cassert>
#include <string>
#include <cstdio>
#include <map>

int numSplits(const std::string &s) {
    if (s.size() <= 1) {
        return 0;
    }

    std::map<char, int> m1, m2;
    for (size_t i = 0; i < s.size(); ++i) {
        ++m2[s[i]];
    }

    int ret = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        ++m1[c];
        --m2[c];

        if (m2[c] == 0) {
            m2.erase(c);
        }

        if (m1.size() == m2.size()) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    assert(numSplits("aacaba") == 2);
    assert(numSplits("abcd") == 1);
    assert(numSplits("aaaaa") == 4);
    assert(numSplits("acbadbaada") == 2);
    return 0;
}
