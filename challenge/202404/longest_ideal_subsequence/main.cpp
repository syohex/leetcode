#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int longestIdealString(const std::string &s, int k) {
    std::vector<int> dp(26, 0);
    int ret = 0;

    for (char c : s) {
        int v = c - 'a';
        int longest = 0;
        for (int i = 0; i < 26; ++i) {
            if (std::abs(v - i) <= k) {
                longest = std::max(longest, dp[i]);
            }
        }

        dp[v] = std::max(dp[v], longest + 1);
        ret = std::max(ret, dp[v]);
    }

    return ret;
}

int main() {
    assert(longestIdealString("acfgbd", 2) == 4);
    assert(longestIdealString("abcd", 3) == 4);
    return 0;
}
