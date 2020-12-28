#include <cassert>
#include <vector>
#include <utility>

void rotate(std::vector<std::vector<int>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i; j < matrix[i].size(); ++j) {
            if (i != j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    for (size_t i = 0; i < matrix.size(); ++i) {
        size_t limit = matrix[i].size() / 2;
        for (size_t j = 0; j < limit; ++j) {
            std::swap(matrix[i][j], matrix[i][matrix[i].size() - 1 - j]);
        }
    }
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> input {
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
        rotate(input);
        assert(input == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
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
        rotate(input);
        assert(input == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1},
        };
        std::vector<std::vector<int>> expected {
            {1},
        };
        // clang-format on
        rotate(input);
        assert(input == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2},
            {3, 4},
        };
        std::vector<std::vector<int>> expected {
            {3, 1},
            {4, 2},
        };
        // clang-format on
        rotate(input);
        assert(input == expected);
    }
    return 0;
}
