#include <cassert>
#include <vector>
#include <utility>

std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &matrix) {
    std::vector<int> ret;
    if (matrix.empty()) {
        return ret;
    }

    int rows = static_cast<int>(matrix.size());
    int cols = static_cast<int>(matrix[0].size());

    bool left_up = true;
    size_t elements = rows * cols;
    for (int i = 0; ret.size() < elements; ++i) {
        int x = 0;
        int y = i;

        int x_step, y_step;
        if (left_up) {
            x_step = -1;
            y_step = 1;
            std::swap(x, y);
        } else {
            x_step = 1;
            y_step = -1;
        }

        while (!(x >= 0 && x < rows && y >= 0 && y < cols)) {
            x += x_step;
            y += y_step;
        }

        for (int i = 0;; ++i) {
            if (!(x >= 0 && x < rows && y >= 0 && y < cols)) {
                break;
            }

            ret.push_back(matrix[x][y]);

            x += x_step;
            y += y_step;
        }

        left_up = !left_up;
    }

    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        // clang-format on
        std::vector<int> expected{1, 2, 4, 7, 5, 3, 6, 8, 9};
        auto ret = findDiagonalOrder(input);
        assert(ret == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1},
        };
        // clang-format on
        std::vector<int> expected{1};
        auto ret = findDiagonalOrder(input);
        assert(ret == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2},
            {4, 5},
            {7, 8},
        };
        // clang-format on
        std::vector<int> expected{1, 2, 4, 7, 5, 8};
        auto ret = findDiagonalOrder(input);
        assert(ret == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
        };
        // clang-format on
        std::vector<int> expected{1, 2, 5, 6, 3, 4, 7, 8};
        auto ret = findDiagonalOrder(input);
        assert(ret == expected);
    }
    return 0;
}
