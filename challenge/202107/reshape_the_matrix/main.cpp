#include <cassert>
#include <vector>

std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>> &mat, int r, int c) {
    size_t size = mat.size() * mat[0].size();
    if (size != r * c) {
        return mat;
    }

    std::vector<std::vector<int>> ret(r, std::vector<int>(c));
    size_t index = 0;
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[0].size(); ++j) {
            auto row = index / c;
            auto col = index % c;
            ret[row][col] = mat[i][j];
            ++index;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> mat{
            {1, 2},
            {3, 4},
        };
        std::vector<std::vector<int>> expected{
            {1, 2, 3, 4},
        };

        auto ret = matrixReshape(mat, 1, 4);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> mat{
            {1, 2},
            {3, 4},
        };
        std::vector<std::vector<int>> expected{
            {1, 2},
            {3, 4},
        };

        auto ret = matrixReshape(mat, 2, 4);
        assert(ret == expected);
    }
    return 0;
}
