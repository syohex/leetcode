#include <cassert>
#include <vector>

bool checkXMatrix(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                if (grid[i][j] == 0) {
                    return false;
                }
            } else if (grid[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {2, 0, 0, 1},
            {0, 3, 1, 0},
            {0, 5, 2, 0},
            {4, 0, 0, 2},
        };
        assert(checkXMatrix(grid));
    }
    {
        std::vector<std::vector<int>> grid{
            {5, 7, 0},
            {0, 3, 1},
            {0, 5, 0},
        };
        assert(!checkXMatrix(grid));
    }
    return 0;
}