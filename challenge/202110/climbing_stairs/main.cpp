#include <cassert>
#include <vector>
#include <functional>
#include <map>

int climbStairs(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    if (n == 1) {
        return dp[1];
    }

    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbStairs2(int n) {
    std::function<int(int m)> f;
    std::map<int, int> cache;
    f = [&](int m) -> int {
        if (m > n) {
            return 0;
        }

        if (m == n) {
            return 1;
        }

        if (cache.find(m) != cache.end()) {
            return cache[m];
        }

        cache[m] = f(m + 1) + f(m + 2);
        return cache[m];
    };

    return f(0);
}

int main() {
    assert(climbStairs(2) == 2);
    assert(climbStairs(3) == 3);
    assert(climbStairs(4) == 5);

    assert(climbStairs2(2) == 2);
    assert(climbStairs2(3) == 3);
    assert(climbStairs2(4) == 5);
    return 0;
}