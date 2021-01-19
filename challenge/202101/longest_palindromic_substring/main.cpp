#include <cassert>
#include <vector>
#include <string>
#include <cstdio>

std::string longestPalindrome(const std::string &s) {
    size_t size = s.size();
    std::vector<std::vector<bool>> dp(size);

    for (size_t i = 0; i < s.size(); ++i) {
        dp[i] = std::vector<bool>(size, false);
        dp[i][i] = true;
    }

    size_t left = size - 1, right = size - 1;
    for (size_t i = 0; i < size - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            left = i;
            right = i + 1;
        }
    }

    for (size_t i = 2; i < size; ++i) {
        for (size_t j = 0, k = i; k < size; ++j, ++k) {
            dp[j][k] = s[j] == s[k] && dp[j + 1][k - 1];
            if (dp[j][k]) {
                left = j;
                right = k;
            }
        }
    }

    return s.substr(left, right - left + 1);
}

int main() {
    assert(longestPalindrome("babad") == "aba");
    assert(longestPalindrome("cbbd") == "bb");
    assert(longestPalindrome("a") == "a");
    assert(longestPalindrome("ac") == "c");
    return 0;
}
