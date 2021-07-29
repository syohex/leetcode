#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> updateMatrix(const std::vector<std::vector<int>> &mat) {
    std::vector<std::vector<int>> ret(mat.size(), std::vector<int>(mat[0].size(), 1'000'000));

    int rows = mat.size();
    int cols = mat[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                ret[i][j] = 0;
            } else {
                if (i > 0) {
                    ret[i][j] = ret[i - 1][j] + 1;
                }
                if (j > 0) {
                    ret[i][j] = std::min(ret[i][j], ret[i][j - 1] + 1);
                }
            }
        }
    }

    for (int i = rows - 1; i >= 0; --i) {
        for (int j = cols - 1; j >= 0; --j) {
            if (mat[i][j] == 0) {
                ret[i][j] = 0;
            } else {
                if (i < rows - 1) {
                    ret[i][j] = std::min(ret[i][j], ret[i + 1][j] + 1);
                }
                if (j < cols - 1) {
                    ret[i][j] = std::min(ret[i][j], ret[i][j + 1] + 1);
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> mat{
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0},
        };
        std::vector<std::vector<int>> expected{
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0},
        };
        auto ret = updateMatrix(mat);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> mat{
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1},
        };
        std::vector<std::vector<int>> expected{
            {0, 0, 0},
            {0, 1, 0},
            {1, 2, 1},
        };
        auto ret = updateMatrix(mat);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> mat{
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
        };
        std::vector<std::vector<int>> expected{
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
        };
        auto ret = updateMatrix(mat);
        assert(ret == expected);
    }
    return 0;
}
