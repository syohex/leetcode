#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int atMostNGivenDigitSet(const std::vector<std::string> &digits, int n) {
    std::vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    int len = v.size();
    int digit_len = digits.size();
    std::vector<int> dp(len + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < len; ++i) {
        dp[len] += std::pow(digit_len, i);
    }

    for (int i = 0; i < len; ++i) {
        for (const auto &d : digits) {
            int m = d[0] - '0';
            if (m < v[i]) {
                dp[i + 1] += std::pow(digit_len, i);
            } else if (m == v[i]) {
                dp[i + 1] += dp[i];
            }
        }
    }

    return dp[len];
}

int main() {
    {
        std::vector<std::string> digits{"1", "3", "5", "7"};
        assert(atMostNGivenDigitSet(digits, 100) == 20);
    }
    {
        std::vector<std::string> digits{"1", "4", "9"};
        assert(atMostNGivenDigitSet(digits, 1000000000) == 29523);
    }
    {
        std::vector<std::string> digits{"7"};
        assert(atMostNGivenDigitSet(digits, 8) == 1);
    }
    {
        std::vector<std::string> digits{"3", "4", "5", "6"};
        assert(atMostNGivenDigitSet(digits, 64) == 18);
    }
    return 0;
}
