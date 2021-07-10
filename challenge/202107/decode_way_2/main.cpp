#include <cassert>
#include <string>
#include <vector>

int numDecoding(const std::string &s) {
    constexpr long MOD = 1'000'000'007;
    std::vector<long> dp(s.size() + 1, 0);

    dp[0] = 1;
    if (s[0] == '*') {
        dp[1] = 9;
    } else if (s[0] == '0') {
        dp[1] = 0;
    } else {
        dp[1] = 1;
    }

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == '*') {
            dp[i + 1] = (dp[i] * 9) % MOD;
            if (s[i - 1] == '1') {
                dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % MOD;
            } else if (s[i - 1] == '2') {
                dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % MOD;
            } else if (s[i - 1] == '*') {
                dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % MOD;
            }
        } else {
            if (s[i] != '0') {
                dp[i + 1] = dp[i];
            }

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
            } else if (s[i - 1] == '*') {
                if (s[i] >= '0' && s[i] <= '6') {
                    dp[i + 1] = (dp[i + 1] + 2 * dp[i - 1]) % MOD;
                } else {
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
                }
            }
        }
    }

    return dp.back();
}

int main() {
    assert(numDecoding("*") == 9);
    assert(numDecoding("1*") == 18);
    assert(numDecoding("2*") == 15);
    return 0;
}