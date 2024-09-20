#include <cassert>
#include <string>
#include <algorithm>
#include <functional>

std::string shortestPalindrome(const std::string &s) {
    std::function<std::string(const std::string &s)> f;
    f = [&](const std::string &s) -> std::string {
        int len = s.size();
        if (len == 0) {
            return "";
        }

        int left = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (s[left] == s[i]) {
                ++left;
            }
        }

        if (left == len) {
            return s;
        }

        std::string suffix = s.substr(left);
        std::string reverse_suffix = std::string(suffix.rbegin(), suffix.rend());

        return reverse_suffix + f(s.substr(0, left)) + suffix;
    };

    return f(s);
}

int main() {
    assert(shortestPalindrome("aacecaaa") == "aaacecaaa");
    assert(shortestPalindrome("abcd") == "dcbabcd");
    return 0;
}