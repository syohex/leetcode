#include <cassert>
#include <vector>

class NeighborSum {
  public:
    NeighborSum(const std::vector<std::vector<int>> &grid) : grid_(grid), rows_(grid.size()), cols_(grid[0].size()) {
    }

    int adjacentSum(int value) {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (grid_[i][j] == value) {
                    return getValue(i - 1, j) + getValue(i, j - 1) + getValue(i + 1, j) + getValue(i, j + 1);
                }
            }
        }

        return 0;
    }

    int diagonalSum(int value) {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (grid_[i][j] == value) {
                    return getValue(i - 1, j - 1) + getValue(i - 1, j + 1) + getValue(i + 1, j - 1) + getValue(i + 1, j + 1);
                }
            }
        }
        return 0;
    }

    int getValue(int row, int col) const {
        if (row >= 0 && row < rows_ && col >= 0 && col < cols_) {
            return grid_[row][col];
        }

        return 0;
    }

    std::vector<std::vector<int>> grid_;
    int rows_;
    int cols_;
};

int main() {
    {
        std::vector<std::vector<int>> grid{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
        NeighborSum n(grid);
        assert(n.adjacentSum(1) == 6);
        assert(n.adjacentSum(4) == 16);
        assert(n.diagonalSum(4) == 16);
        assert(n.diagonalSum(8) == 4);
    }
    {
        std::vector<std::vector<int>> grid{{1, 2, 0, 3}, {4, 7, 15, 6}, {8, 9, 10, 11}, {12, 13, 14, 5}};
        NeighborSum n(grid);
        assert(n.adjacentSum(15) == 23);
        assert(n.diagonalSum(9) == 45);
    }
    return 0;
}
