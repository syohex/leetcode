#include <cassert>
#include <string>
#include <cctype>

bool isPalindrome(const std::string &s) {
    const auto to_lower = [](char c) -> char {
        if (c >= 'A' && c <= 'Z') {
            return 'a' + c - 'A';
        }

        return c;
    };

    int limit = static_cast<int>(s.size());
    int start = 0;
    int end = limit - 1;
    while (true) {
        while (start < limit && !isalnum(static_cast<int>(s[start]))) {
            ++start;
        }

        while (end >= 0 && !isalnum(static_cast<int>(s[end]))) {
            --end;
        }

        if (start >= end || start >= limit || end < 0) {
            return true;
        }

        if (to_lower(s[start]) != to_lower(s[end])) {
            return false;
        }

        ++start;
        --end;
    }
}

int main() {
    assert(isPalindrome(""));
    assert(isPalindrome("a"));
    assert(!isPalindrome("apple"));
    assert(isPalindrome("A man, a plan a canal: Panama"));
    assert(!isPalindrome("race a car"));
    assert(!isPalindrome("0p"));
    return 0;
}
