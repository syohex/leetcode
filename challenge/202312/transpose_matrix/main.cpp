#include <cassert>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> ret(cols, std::vector<int>(rows, 0));

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            ret[i][j] = matrix[j][i];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        std::vector<std::vector<int>> expected{
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
        };
        auto ret = transpose(matrix);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3},
            {4, 5, 6},
        };
        std::vector<std::vector<int>> expected{
            {1, 4},
            {2, 5},
            {3, 6},
        };
        auto ret = transpose(matrix);
        assert(ret == expected);
    }
    return 0;
}
