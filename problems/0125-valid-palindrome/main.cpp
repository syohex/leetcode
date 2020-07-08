#include <cassert>
#include <string>
#include <functional>
#include <cctype>

bool isPalindrome(const std::string &s) {
    if (s.size() <= 1) {
        return true;
    }

    auto toLower = [](char c) -> char {
        if (c >= 'A' && c <= 'Z') {
            return c + 'a' - 'A';
        }
        return c;
    };

    int left = 0, right = static_cast<int>(s.size()) - 1;
    while (left <= right) {
        while (!isalnum(static_cast<int>(s[left]))) {
            ++left;
            if (left > right) {
                return true;
            }
        }
        while (!isalnum(static_cast<int>(s[right]))) {
            --right;
            if (left > right) {
                return true;
            }
        }

        if (toLower(s[left]) != toLower(s[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

int main() {
    assert(isPalindrome("A man, a plan, a canal: Panama"));
    assert(!isPalindrome("race a car"));
    assert(isPalindrome(",!"));
    assert(!isPalindrome("0P"));
    return 0;
}
