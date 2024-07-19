#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> luckyNumbers(const std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<int> row_min;
    for (int i = 0; i < rows; ++i) {
        row_min.push_back(*std::min_element(matrix[i].begin(), matrix[i].end()));
    }

    std::vector<int> col_max;
    for (int j = 0; j < cols; ++j) {
        int max = 0;
        for (int i = 0; i < rows; ++i) {
            max = std::max(max, matrix[i][j]);
        }
        col_max.push_back(max);
    }

    std::vector<int> ret;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j]) {
                ret.push_back(matrix[i][j]);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
        std::vector<int> expected{15};
        auto ret = luckyNumbers(matrix);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{{7, 8}, {1, 2}};
        std::vector<int> expected{7};
        auto ret = luckyNumbers(matrix);
        assert(ret == expected);
    }
    return 0;
}