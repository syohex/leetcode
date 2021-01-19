#include <cassert>
#include <vector>
#include <string>
#include <cstdio>

std::string longestPalindrome(const std::string &s) {
    size_t size = s.size();
    std::vector<std::vector<bool>> dp(size);
    for (size_t i = 0; i < s.size(); ++i) {
        dp[i] = std::vector<bool>(size, false);
    }

    std::string ret;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0, k = i; k < size; ++j, ++k) {
            if (i == 0) {
                dp[j][k] = true;
            } else if (i == 1) {
                dp[j][k] = s[j] == s[k];
            } else {
                dp[j][k] = s[j] == s[k] && dp[j + 1][k - 1];
            }

            if (dp[j][k]) {
                ret = s.substr(j, k - j + 1);
            }
        }
    }

    return ret;
}

int main() {
    assert(longestPalindrome("babad") == "aba");
    assert(longestPalindrome("cbbd") == "bb");
    assert(longestPalindrome("a") == "a");
    assert(longestPalindrome("ac") == "c");
    return 0;
}
