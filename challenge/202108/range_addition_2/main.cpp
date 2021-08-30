#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int maxCount(int m, int n, const std::vector<std::vector<int>> &ops) {
    if (ops.empty()) {
        return m * n;
    }

    int min_row = INT_MAX;
    int min_col = INT_MAX;

    for (const auto &op : ops) {
        min_row = std::min(min_row, op[0]);
        min_col = std::min(min_col, op[1]);
    }

    return min_row * min_col;
}

int main() {
    {
        std::vector<std::vector<int>> ops{
            {2, 2},
            {3, 3},
        };
        assert(maxCount(3, 3, ops) == 4);
    }
    {
        std::vector<std::vector<int>> ops{
            {2, 2}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {3, 3}, {3, 3}, {3, 3},
        };
        assert(maxCount(3, 3, ops) == 4);
    }
    {
        std::vector<std::vector<int>> ops{};
        assert(maxCount(3, 3, ops) == 9);
    }
    return 0;
}