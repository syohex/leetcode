#include <cassert>
#include <string>
#include <algorithm>

std::string makeFancyString(const std::string &s) {
    std::string ret;
    char prev = s[0];
    int count = 1;

    for (size_t i = 1; i < s.size(); ++i) {
        if (prev == s[i]) {
            ++count;
        } else {
            int len = std::min(count, 2);
            for (int i = 0; i < len; ++i) {
                ret.push_back(prev);
            }

            prev = s[i];
            count = 1;
        }
    }

    int len = std::min(count, 2);
    for (int i = 0; i < len; ++i) {
        ret.push_back(prev);
    }
    return ret;
}

int main() {
    assert(makeFancyString("leeetcode") == "leetcode");
    assert(makeFancyString("aaabaaaa") == "aabaa");
    assert(makeFancyString("aab") == "aab");
    return 0;
}