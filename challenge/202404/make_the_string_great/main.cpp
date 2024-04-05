#include <cassert>
#include <string>
#include <cctype>

std::string makeGood(std::string s) {
    int len = s.size();
    for (int i = 1; i < len; ++i) {
        int prev = i - 1;
        while (prev >= 0 && s[prev] == 0) {
            --prev;
        }

        if (prev < 0 || s[i] == s[prev]) {
            continue;
        }

        if (std::tolower(s[i]) == std::tolower(s[prev])) {
            s[i] = 0;
            s[prev] = 0;
        }
    }

    std::string ret;
    for (char c : s) {
        if (c != 0) {
            ret.push_back(c);
        }
    }

    return ret;
}

int main() {
    assert(makeGood("leEeetcode") == "leetcode");
    assert(makeGood("abBAcC") == "");
    assert(makeGood("s") == "s");
    assert(makeGood("Pp") == "");
    return 0;
}
