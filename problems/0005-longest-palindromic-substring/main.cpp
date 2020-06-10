#include <cassert>
#include <string>

std::string longestPalindrome(const std::string &s) {
    const auto f = [](const std::string &substr) -> bool {
        for (size_t i = 0; i < substr.size() / 2; ++i) {
            if (substr[i] != substr[substr.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    };

    for (size_t i = s.size(); i > 0; --i) {
        for (size_t j = 0; j + i <= s.size(); ++j) {
            const std::string substr = s.substr(j, i);
            if (f(substr)) {
                return substr;
            }
        }
    }

    return "";
}

int main() {
    assert(longestPalindrome("babad") == "bab");
    assert(longestPalindrome("cbbd") == "bb");
    assert(longestPalindrome("abba") == "abba");
    return 0;
}
