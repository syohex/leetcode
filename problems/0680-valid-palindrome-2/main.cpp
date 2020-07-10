#include <cassert>
#include <string>
#include <functional>

bool validPalindrome(const std::string &s) {
    if (s.size() <= 2) {
        return true;
    }

    std::function<bool(const std::string &str, int miss)> f;
    f = [&f](const std::string &str, int miss) -> bool {
        int left = 0, right = static_cast<int>(str.size() - 1);
        while (left <= right) {
            if (str[left] == str[right]) {
                ++left;
                --right;
            } else {
                if (miss >= 1) {
                    return false;
                }

                std::string strL = str.substr(0, left) + str.substr(left + 1);
                std::string strR = str.substr(0, right) + str.substr(right + 1);
                return f(strL, miss + 1) || f(strR, miss + 1);
            }
        }

        return true;
    };

    return f(s, 0);
}

int main() {
    assert(validPalindrome("aba"));
    assert(validPalindrome("abca"));
    assert(validPalindrome("deeee"));
    return 0;
}
