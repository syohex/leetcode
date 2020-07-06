#include <cassert>
#include <vector>

int countSquares(const std::vector<std::vector<int>> &matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    size_t limit = rows > cols ? rows : cols;

    int ret = 0;
    for (size_t i = 1; i < limit; ++i) {
        int total = static_cast<int>(i * i);
        int orig = ret;
        for (size_t j = 0; j <= rows - i; ++j) {
            for (size_t k = 0; k <= cols - i; ++k) {
                int ones = 0;
                for (size_t x = 0; x < i; ++x) {
                    for (size_t y = 0; y < i; ++y) {
                        if (matrix[j + x][k + y] == 1) {
                            ++ones;
                        }
                    }
                }

                if (ones == total) {
                    ++ret;
                }
            }
        }

        // If current square size is not found in matrix, there are no squares
        if (orig == ret) {
            return ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {0, 1, 1, 1},
            {1, 1, 1, 1},
            {0, 1, 1, 1},
        };
        assert(countSquares(input) == 15);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 0, 1},
            {1, 1, 0},
            {1, 1, 0},
        };
        assert(countSquares(input) == 7);
    }
    return 0;
}
