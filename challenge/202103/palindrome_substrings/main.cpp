#include <cassert>
#include <string>
#include <vector>

int countSubstrings(const std::string &s) {
    int limit = s.size();
    std::vector<std::vector<bool>> dp(limit, std::vector<bool>(limit, false));

    int ret = 0;
    for (int i = 0; i < limit; ++i) {
        dp[i][i] = true;
        ++ret;
    }

    for (int i = 0; i < limit - 1; ++i) {
        dp[i][i + 1] = s[i] == s[i + 1];
        if (dp[i][i + 1]) {
            ++ret;
        }
    }

    for (int i = 3; i <= limit; ++i) {
        for (int j = 0, k = j + i - 1; k < limit; ++j, ++k) {
            dp[j][k] = dp[j + 1][k - 1] && s[j] == s[k];
            if (dp[j][k]) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    assert(countSubstrings("abc") == 3);
    assert(countSubstrings("aaa") == 6);
    return 0;
}
