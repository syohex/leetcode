#include <cassert>
#include <vector>
#include <cstdio>

int numSpecial(const std::vector<std::vector<int>> &mat) {
    size_t rows = mat.size();
    size_t cols = mat[0].size();
    if (rows == 1 || cols == 1) {
        return 0;
    }

    int ret = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (mat[i][j] != 1) {
                continue;
            }

            bool ok = true;
            for (size_t k = 0; k < cols; ++k) {
                if (k == j) {
                    continue;
                }
                if (mat[i][k] == 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                for (size_t k = 0; k < rows; ++k) {
                    if (k == i) {
                        continue;
                    }
                    if (mat[k][j] == 1) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) {
                ++ret;
                break;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 0, 0},
            {0, 0, 1},
            {1, 0, 0},
        };
        assert(numSpecial(input) == 1);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
        };
        assert(numSpecial(input) == 3);
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0, 0, 1},
            {1, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        };
        assert(numSpecial(input) == 2);
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1},
        };
        assert(numSpecial(input) == 3);
    }
    return 0;
}
