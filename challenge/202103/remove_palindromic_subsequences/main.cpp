#include <cassert>
#include <string>
#include <algorithm>

int removePalindromeSub(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    std::string tmp(s);
    std::reverse(tmp.begin(), tmp.end());
    return s == tmp ? 1 : 2;
}

int main() {
    assert(removePalindromeSub("ababa") == 1);
    assert(removePalindromeSub("abb") == 2);
    assert(removePalindromeSub("baabb") == 2);
    assert(removePalindromeSub("") == 0);
    return 0;
}
