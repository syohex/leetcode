#include <cassert>
#include <vector>

bool satisfiesConditions(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (grid[i][j] != grid[0][j]) {
                return false;
            }

            if (j + 1 < cols) {
                if (grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> grid{{1, 0, 2}, {1, 0, 2}};
        assert(satisfiesConditions(grid));
    }
    {
        std::vector<std::vector<int>> grid{{1, 1, 1}, {0, 0, 0}};
        assert(!satisfiesConditions(grid));
    }
    {
        std::vector<std::vector<int>> grid{{1}, {2}, {3}};
        assert(!satisfiesConditions(grid));
    }
    return 0;
}
