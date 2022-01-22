#include <cassert>
#include <map>
#include <cmath>
#include <functional>
#include <vector>

bool winnerSquareGame(int n) {
    std::vector<bool> dp(n + 1, false);
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (!dp[i - (j * j)]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    assert(winnerSquareGame(1));
    assert(!winnerSquareGame(2));
    assert(winnerSquareGame(4));
    return 0;
}
