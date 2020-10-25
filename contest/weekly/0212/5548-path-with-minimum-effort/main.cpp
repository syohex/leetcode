#include <cassert>
#include <vector>
#include <cstdio>
#include <set>
#include <functional>
#include <algorithm>
#include <climits>

int minimumEffortPath(const std::vector<std::vector<int>> &heights) {
    int ret = INT_MAX;
    std::function<void(size_t row, size_t col, int max, const std::set<size_t> &s)> f;
    f = [&f, &heights, &ret](size_t row, size_t col, int max, const std::set<size_t> &s) {
        if (max >= ret) {
            return;
        }

        if (row == heights.size() - 1 && col == heights[0].size() - 1) {
            if (max < ret) {
                ret = max;
            }
        }

        size_t down = row + 1;
        size_t down_index = down * heights.size() + col;
        if (down <= heights.size() - 1 && s.find(down_index) == s.end()) {
            auto new_s = s;
            new_s.insert(down_index);

            int new_diff = std::abs(heights[down][col] - heights[row][col]);
            f(down, col, std::max(max, new_diff), new_s);
        }

        size_t right = col + 1;
        size_t right_index = row * heights.size() + right;
        if (right <= heights[0].size() - 1 && s.find(right_index) == s.end()) {
            auto new_s = s;
            new_s.insert(right_index);

            int new_diff = std::abs(heights[row][right] - heights[row][col]);
            f(row, right, std::max(max, new_diff), new_s);
        }

        size_t up = row - 1;
        size_t up_index = up * heights.size() + col;
        if (row > 0 && s.find(up_index) == s.end()) {
            auto new_s = s;
            new_s.insert(up_index);

            int new_diff = std::abs(heights[up][col] - heights[row][col]);
            f(up, col, std::max(max, new_diff), new_s);
        }

        size_t left = col - 1;
        size_t left_index = row * heights.size() + left;
        if (col > 0 && s.find(left_index) == s.end()) {
            auto new_s = s;
            new_s.insert(left_index);

            int new_diff = std::abs(heights[row][left] - heights[row][col]);
            f(row, left, std::max(max, new_diff), new_s);
        }
    };

    std::set<size_t> s{0};
    f(0, 0, 0, s);

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5},
        };
        assert(minimumEffortPath(input) == 2);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 2, 3},
            {3, 8, 4},
            {5, 3, 5},
        };
        assert(minimumEffortPath(input) == 1);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1},
        };
        assert(minimumEffortPath(input) == 0);
    }
    {
        std::vector<std::vector<int>> input{
            {10, 8}, {10, 8}, {1, 2}, {10, 3}, {1, 3}, {6, 3}, {5, 2},
        };
        assert(minimumEffortPath(input) == 6);
    }
    return 0;
}
