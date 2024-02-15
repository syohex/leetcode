#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> modifiedMatrix(std::vector<std::vector<int>> &matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    std::vector<int> max_rows(cols, -2);

    for (size_t i = 0; i < cols; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            max_rows[i] = std::max(max_rows[i], matrix[j][i]);
        }
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = max_rows[j];
            }
        }
    }

    return matrix;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, -1},
            {4, -1, 6},
            {7, 8, 9},
        };
        std::vector<std::vector<int>> expected{
            {1, 2, 9},
            {4, 8, 6},
            {7, 8, 9},
        };

        auto ret = modifiedMatrix(matrix);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {3, -1},
            {5, 2},
        };
        std::vector<std::vector<int>> expected{
            {3, 2},
            {5, 2},
        };

        auto ret = modifiedMatrix(matrix);
        assert(ret == expected);
    }
    return 0;
}
