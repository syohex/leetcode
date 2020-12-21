#include <cassert>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix) {
    auto tmp = matrix;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = tmp[matrix.size() - 1 - j][i];
        }
    }
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> matrix {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        std::vector<std::vector<int>> expected {
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3},
        };
        // clang-format on

        rotate(matrix);
        assert(matrix == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> matrix {
            {5, 1, 9, 11},
            {2, 4, 8, 10},
            {13, 3, 6, 7},
            {15, 14, 12, 16},
        };
        std::vector<std::vector<int>> expected {
            {15, 13, 2, 5},
            {14, 3, 4, 1},
            {12, 6, 8, 9},
            {16, 7, 10, 11},
        };
        // clang-format on

        rotate(matrix);
        assert(matrix == expected);
    }
    return 0;
}
