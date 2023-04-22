#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> findColumnWidth(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<int> ret;

    for (int i = 0; i < cols; ++i) {
        int len = 0;
        for (int j = 0; j < rows; ++j) {
            len = std::max(len, static_cast<int>(std::to_string(grid[j][i]).size()));
        }
        ret.push_back(len);
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{{1}, {22}, {333}};
        std::vector<int> expected{3};
        auto ret = findColumnWidth(grid);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> grid{{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}};
        std::vector<int> expected{3, 1, 2};
        auto ret = findColumnWidth(grid);
        assert(ret == expected);
    }
    return 0;
}
