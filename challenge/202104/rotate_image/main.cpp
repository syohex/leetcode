#include <cassert>
#include <vector>
#include <utility>

void rotate(std::vector<std::vector<int>> &matrix) {
    int max_row = matrix.size() - 1;
    int half = matrix.size() / 2;
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::swap(matrix[i][j], matrix[max_row - i][j]);
        }
    }

    for (int i = 0; i <= max_row; ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        std::vector<std::vector<int>> expected{
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3},
        };
        rotate(matrix);
        assert(matrix == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {5, 1, 9, 11},
            {2, 4, 8, 10},
            {13, 3, 6, 7},
            {15, 14, 12, 16},
        };
        std::vector<std::vector<int>> expected{
            {15, 13, 2, 5},
            {14, 3, 4, 1},
            {12, 6, 8, 9},
            {16, 7, 10, 11},
        };
        rotate(matrix);
        assert(matrix == expected);
    }
    {
        std::vector<std::vector<int>> matrix{{1}};
        std::vector<std::vector<int>> expected{{1}};
        rotate(matrix);
        assert(matrix == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2},
            {3, 4},
        };
        std::vector<std::vector<int>> expected{{3, 1}, {4, 2}};
        rotate(matrix);
        assert(matrix == expected);
    }
    return 0;
}