#include <cassert>
#include <utility>
#include <vector>
#include <cstdio>

double knightProbability(int n, int k, int row, int column) {
    std::vector<std::vector<std::vector<double>>> dp(k + 1, std::vector<std::vector<double>>(n, std::vector<double>(n, 0)));
    std::vector<std::pair<int, int>> steps{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

    dp[0][row][column] = 1;

    for (int time = 1; time <= k; ++time) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (const auto &[x, y] : steps) {
                    int prev_r = i - x;
                    int prev_c = j - y;

                    if (prev_r >= 0 && prev_r < n && prev_c >= 0 && prev_c < n) {
                        dp[time][i][j] += dp[time - 1][prev_r][prev_c] / 8;
                    }
                }
            }
        }
    }

    double ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret += dp[k][i][j];
        }
    }

    return ret;
}

int main() {
    {
        double ret = knightProbability(3, 2, 0, 0);
        assert(ret == 0.06250);
    }
    {
        double ret = knightProbability(1, 0, 0, 0);
        assert(ret == 1);
    }
    return 0;
}
