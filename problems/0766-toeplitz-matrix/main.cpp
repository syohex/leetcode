#include <cassert>
#include <vector>

bool isToeplitzMatrix(const std::vector<std::vector<int>> &matrix) {
    size_t rows = matrix.size();
    size_t columns = matrix[0].size();
    if (rows == 1 || columns == 1) {
        return true;
    }

    for (size_t i = 0; i < rows; ++i) {
        int base = matrix[i][0];
        for (size_t j = 1; i + j < rows && j < columns; ++j) {
            if (base != matrix[i + j][j]) {
                return false;
            }
        }
    }

    for (size_t i = 1; i < columns; ++i) {
        int base = matrix[0][i];
        for (size_t j = 1; j < rows && i + j < columns; ++j) {
            if (base != matrix[j][i + j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2, 3, 4},
            {5, 1, 2, 3},
            {9, 5, 1, 2},
        };

        assert(isToeplitzMatrix(input));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 2},
            {2, 2},
        };

        assert(!isToeplitzMatrix(input));
    }
    {
        std::vector<std::vector<int>> input{
            {84},
        };

        assert(isToeplitzMatrix(input));
    }
    return 0;
}
