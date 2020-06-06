#include <cassert>
#include <vector>

std::vector<int> luckyNumbers(const std::vector<std::vector<int>> &matrix) {
    std::vector<int> ret;
    if (matrix.empty()) {
        return ret;
    }

    size_t rows = matrix.size();
    size_t columns = matrix[0].size();

    for (size_t i = 0; i < rows; ++i) {
        size_t min_col = 0;
        for (size_t j = 1; j < columns; ++j) {
            if (matrix[i][min_col] > matrix[i][j]) {
                min_col = j;
            }
        }

        size_t max_row = i;
        for (size_t j = 0; j < rows; ++j) {
            if (matrix[j][min_col] > matrix[max_row][min_col]) {
                max_row = j;
            }
        }

        if (max_row == i) {
            ret.push_back(matrix[max_row][min_col]);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {3, 7, 8},
            {9, 11, 13},
            {15, 16, 17},
        };
        std::vector<int> ret = luckyNumbers(input);
        assert((ret == std::vector<int>{15}));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 10, 4, 2},
            {9, 3, 8, 7},
            {15, 16, 17, 12},
        };
        std::vector<int> ret = luckyNumbers(input);
        assert((ret == std::vector<int>{12}));
    }
    {
        std::vector<std::vector<int>> input{
            {7, 8},
            {1, 2},
        };
        std::vector<int> ret = luckyNumbers(input);
        assert((ret == std::vector<int>{7}));
    }
}
