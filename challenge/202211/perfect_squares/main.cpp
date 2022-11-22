#include <cassert>
#include <vector>
#include <algorithm>

int numSquares(int n) {
    std::vector<int> squares;
    for (int i = 1; i * i <= n; ++i) {
        squares.push_back(i * i);
    }

    std::vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int square : squares) {
            if (square > i) {
                break;
            }

            dp[i] = std::min(dp[i], dp[i - square] + 1);
        }
    }

    return dp[n];
}

int main() {
    assert(numSquares(1) == 1);
    assert(numSquares(4) == 1);
    assert(numSquares(9) == 1);
    assert(numSquares(12) == 3);
    assert(numSquares(13) == 2);
    assert(numSquares(43) == 3);
    return 0;
}
