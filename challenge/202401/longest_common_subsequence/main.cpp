#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int longestCommonSubsequence(const std::string &text1, const std::string &text2) {
    int len1 = text1.size();
    int len2 = text2.size();

    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            if (text1[i] == text2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][0];
}

int main() {
    assert(longestCommonSubsequence("abcde", "ace") == 3);
    assert(longestCommonSubsequence("abc", "abc") == 3);
    assert(longestCommonSubsequence("abc", "def") == 0);
    return 0;
}
