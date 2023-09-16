#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <cmath>
#include <cstdio>

int minimumEffortPath(const std::vector<std::vector<int>> &heights) {
    int rows = heights.size();
    int cols = heights[0].size();

    struct Data {
        int row;
        int col;
        int max_diff;
    };

    const auto cmp = [](const Data &a, const Data &b) -> bool { return a.max_diff > b.max_diff; };

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
    dp[0][0] = 0;

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({0, 0, 0});

    std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    while (!q.empty()) {
        auto d = q.top();
        q.pop();

        for (const auto &[x, y] : steps) {
            int row = d.row + x;
            int col = d.col + y;

            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                int diff = std::abs(heights[row][col] - heights[d.row][d.col]);
                int v = std::max(diff, dp[d.row][d.col]);
                if (v < dp[row][col]) {
                    q.push({row, col, v});
                    dp[row][col] = v;
                }
            }
        }
    }

    return dp[rows - 1][cols - 1];
}

int main() {
    {
        std::vector<std::vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
        int ret = minimumEffortPath(heights);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
        int ret = minimumEffortPath(heights);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<int>> heights{
            {1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1},
        };
        int ret = minimumEffortPath(heights);
        assert(ret == 0);
    }
    {
        std::vector<std::vector<int>> heights{{3}};
        int ret = minimumEffortPath(heights);
        assert(ret == 0);
    }
    {
        std::vector<std::vector<int>> heights{{1, 10, 6, 7, 9, 10, 4, 9}};
        int ret = minimumEffortPath(heights);
        assert(ret == 9);
    }
    return 0;
}
