#include <cassert>
#include <vector>
#include <cstdio>

int diagonalSum(const std::vector<std::vector<int>> &mat) {
    size_t size = mat.size();
    if (size == 1) {
        return mat[0][0];
    }

    int ret = 0;
    for (size_t i = 0; i < size; ++i) {
        ret += mat[i][i] + mat[size - 1 - i][i];
    }

    if (size % 2 == 1) {
        size_t index = (mat.size() - 1) / 2;
        ret -= mat[index][index];
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        assert(diagonalSum(input) == 25);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
        };
        assert(diagonalSum(input) == 8);
    }
    {
        std::vector<std::vector<int>> input{
            {5},
        };
        assert(diagonalSum(input) == 5);
    }
    return 0;
}
