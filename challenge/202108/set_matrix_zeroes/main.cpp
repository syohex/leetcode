#include <cassert>
#include <vector>
#include <set>

void setZeros(std::vector<std::vector<int>> &matrix) {
    std::set<size_t> rows;
    std::set<size_t> cols;

    size_t row_len = matrix.size();
    size_t col_len = matrix[0].size();
    for (size_t i = 0; i < row_len; ++i) {
        for (size_t j = 0; j < col_len; ++j) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (auto row : rows) {
        for (size_t col = 0; col < col_len; ++col) {
            matrix[row][col] = 0;
        }
    }
    for (auto col : cols) {
        for (size_t row = 0; row < row_len; ++row) {
            matrix[row][col] = 0;
        }
    }
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
        };
        std::vector<std::vector<int>> expected{
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1},
        };
        setZeros(matrix);
        assert(matrix == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5},
        };
        std::vector<std::vector<int>> expected{
            {0, 0, 0, 0},
            {0, 4, 5, 0},
            {0, 3, 1, 0},
        };
        setZeros(matrix);
        assert(matrix == expected);
    }
    return 0;
}
