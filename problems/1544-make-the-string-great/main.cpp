#include <cassert>
#include <string>
#include <cstdio>

std::string makeGood(const std::string &s) {
    if (s.size() <= 1) {
        return s;
    }

    size_t pos = 0;
    std::string ret(s.size(), 0);
    ret[pos++] = s[0];

    for (size_t i = 1; i < s.size(); ++i) {
        if (pos == 0) {
            ret[pos++] = s[i];
        } else if (ret[pos - 1] == (s[i] + 'a' - 'A') || ret[pos - 1] == (s[i] + 'A' - 'a')) {
            --pos;
        } else {
            ret[pos++] = s[i];
        }
    }

    ret.resize(pos);
    return ret;
}

int main() {
    assert(makeGood("leEeetcode") == "leetcode");
    assert(makeGood("abBAcC") == "");
    assert(makeGood("s") == "s");
    return 0;
}
