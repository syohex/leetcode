#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <algorithm>

int minimumEffortPath(const std::vector<std::vector<int>> &heights) {
    struct Data {
        int row;
        int col;
        int diff;
    };

    const auto cmp = [](const Data &a, const Data &b) { return a.diff > b.diff; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({0, 0, 0});

    int rows = heights.size();
    int cols = heights[0].size();

    std::vector<std::vector<int>> table(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
    std::vector<std::vector<bool>> checked(rows, std::vector<bool>(cols, false));

    table[0][0] = 0;
    checked[0][0] = true;

    const std::vector<std::vector<int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!q.empty()) {
        Data d = q.top();
        q.pop();

        int height1 = heights[d.row][d.col];
        for (const auto &step : steps) {
            int new_row = d.row + step[0];
            int new_col = d.col + step[1];

            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !checked[new_row][new_col]) {
                int height2 = heights[new_row][new_col];
                int diff = std::max(table[d.row][d.col], std::abs(height2 - height1));

                if (diff < table[new_row][new_col]) {
                    table[new_row][new_col] = diff;
                    checked[new_row][new_col] = true;

                    q.push({new_row, new_col, diff});
                }
            }
        }
    }

    return table[rows - 1][cols - 1];
}

int main() {
    // {
    //     std::vector<std::vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    //     assert(minimumEffortPath(heights) == 2);
    // }
    // {
    //     std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    //     assert(minimumEffortPath(heights) == 1);
    // }
    // {
    //     std::vector<std::vector<int>> heights{{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2,
    //     1}}; assert(minimumEffortPath(heights) == 0);
    // }
    // {
    //     std::vector<std::vector<int>> heights{{3}};
    //     assert(minimumEffortPath(heights) == 0);
    // }
    {
        std::vector<std::vector<int>> heights{{1, 10, 6, 7, 9, 10, 4, 9}};
        assert(minimumEffortPath(heights) == 9);
    }
    return 0;
}