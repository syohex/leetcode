#include <cassert>
#include <vector>
#include <functional>

std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return std::vector<std::vector<int>>{};
    }
    int cols = matrix[0].size();
    if (cols == 0) {
        return std::vector<std::vector<int>>{};
    }

    std::vector<std::vector<bool>> pacificable(rows, std::vector<bool>(cols, false));
    std::function<bool(std::vector<std::vector<bool>> & checked, int row, int col)> pf;
    pf = [&pf, &matrix, &pacificable, &rows, &cols](std::vector<std::vector<bool>> &checked, int row, int col) -> bool {
        checked[row][col] = true;
        if (pacificable[row][col] || row == 0 || col == 0) {
            return true;
        }

        bool ret = false;
        // up
        if (!ret && row >= 1 && !checked[row - 1][col]) {
            if (matrix[row][col] >= matrix[row - 1][col]) {
                ret = pf(checked, row - 1, col);
            }
        }
        // left
        if (!ret && col >= 1 && !checked[row][col - 1]) {
            if (matrix[row][col] >= matrix[row][col - 1]) {
                ret = pf(checked, row, col - 1);
            }
        }
        // down
        if (!ret && row + 1 < rows && !checked[row + 1][col]) {
            if (matrix[row][col] >= matrix[row + 1][col]) {
                ret = pf(checked, row + 1, col);
            }
        }
        // right
        if (!ret && col + 1 < cols && !checked[row][col + 1]) {
            if (matrix[row][col] >= matrix[row][col + 1]) {
                ret = pf(checked, row, col + 1);
            }
        }

        return ret;
    };

    std::vector<std::vector<bool>> atlanticable(rows, std::vector<bool>(cols, false));
    std::function<bool(std::vector<std::vector<bool>> & checked, int row, int col)> af;
    af = [&af, &matrix, &atlanticable, &rows, &cols](std::vector<std::vector<bool>> &checked, int row, int col) -> bool {
        checked[row][col] = true;
        if (atlanticable[row][col] || row == rows - 1 || col == cols - 1) {
            return true;
        }

        bool ret = false;
        // up
        if (!ret && row >= 1 && !checked[row - 1][col]) {
            if (matrix[row][col] >= matrix[row - 1][col]) {
                ret = af(checked, row - 1, col);
            }
        }
        // left
        if (!ret && col >= 1 && !checked[row][col - 1]) {
            if (matrix[row][col] >= matrix[row][col - 1]) {
                ret = af(checked, row, col - 1);
            }
        }
        // down
        if (!ret && row + 1 < rows && !checked[row + 1][col]) {
            if (matrix[row][col] >= matrix[row + 1][col]) {
                ret = af(checked, row + 1, col);
            }
        }
        // right
        if (!ret && col + 1 < cols && !checked[row][col + 1]) {
            if (matrix[row][col] >= matrix[row][col + 1]) {
                ret = af(checked, row, col + 1);
            }
        }

        return ret;
    };

    for (int i = 0; i < rows; ++i) {
        pacificable[i][0] = true;
        atlanticable[i][cols - 1] = true;
    }
    for (int i = 0; i < cols; ++i) {
        pacificable[0][i] = true;
        atlanticable[rows - 1][i] = true;
    }

    std::vector<std::vector<bool>> checked(rows, std::vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!pacificable[i][j]) {
                checked = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
                pacificable[i][j] = pf(checked, i, j);
            }
            if (!atlanticable[i][j]) {
                checked = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
                atlanticable[i][j] = af(checked, i, j);
            }
        }
    }

    std::vector<std::vector<int>> ret;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (pacificable[i][j] && atlanticable[i][j]) {
                ret.push_back(std::vector<int>{i, j});
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4},
        };
        std::vector<std::vector<int>> expected{
            {0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0},
        };
        auto ret = pacificAtlantic(matrix);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5},
        };
        std::vector<std::vector<int>> expected{
            {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2},
        };
        auto ret = pacificAtlantic(matrix);
        assert(ret == expected);
    }
    return 0;
}
