#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>

int minimumEffortPath(const std::vector<std::vector<int>> &heights) {
    struct Node {
        int row;
        int col;
        int distance;
    };
    const auto cmp = [](const Node &a, const Node &b) { return a.distance > b.distance; };

    std::vector<std::vector<int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int row_limit = heights.size();
    int col_limit = heights[0].size();
    std::vector<std::vector<int>> table(row_limit, std::vector<int>(col_limit, INT_MAX));
    std::vector<std::vector<bool>> checked(row_limit, std::vector<bool>(col_limit, false));

    table[0][0] = 0;
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> queue(cmp);
    queue.emplace(Node{0, 0, 0});

    while (!queue.empty()) {
        auto node = queue.top();
        queue.pop();

        checked[node.row][node.col] = true;

        if (node.row == row_limit - 1 && node.col == col_limit - 1) {
            return node.distance;
        }

        for (const auto &move : moves) {
            int r = node.row + move[0];
            int c = node.col + move[1];

            if (r >= 0 && r < row_limit && c >= 0 && c < col_limit && !checked[r][c]) {
                int diff = std::abs(heights[r][c] - heights[node.row][node.col]);
                int max_diff = std::max(diff, table[node.row][node.col]);
                if (max_diff < table[r][c]) {
                    table[r][c] = max_diff;
                    queue.emplace(Node{r, c, max_diff});
                }
            }
        }
    }

    return table[row_limit - 1][col_limit - 1];
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5},
        };
        // clang-format on
        assert(minimumEffortPath(input) == 2);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2, 3},
            {3, 8, 4},
            {5, 3, 5},
        };
        // clang-format on
        assert(minimumEffortPath(input) == 1);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2, 1, 1, 1},
            {1, 2, 1, 2, 1},
            {1, 2, 1, 2, 1},
            {1, 2, 1, 2, 1},
            {1, 1, 1, 2, 1},
        };
        // clang-format on
        assert(minimumEffortPath(input) == 0);
    }
    return 0;
}
