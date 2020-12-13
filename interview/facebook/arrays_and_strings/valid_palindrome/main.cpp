#include <cassert>
#include <string>

bool isPalindrome(const std::string &s) {
    const auto to_lower = [](char c) -> char {
        if (c >= 'A' && c <= 'Z') {
            return c + 'a' - 'A';
        }

        return c;
    };
    const auto is_alnum = [](char c) -> bool { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'); };

    int left = 0;
    int right = static_cast<int>(s.size() - 1);

    while (left < right) {
        while (left < right && !is_alnum(s[left])) {
            ++left;
        }
        while (left < right && !is_alnum(s[right])) {
            --right;
        }

        if (to_lower(s[left]) != to_lower(s[right])) {
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
    assert(isPalindrome("             a    "));
    assert(isPalindrome(""));
    assert(isPalindrome("aba"));
    assert(isPalindrome("a"));
    return 0;
}