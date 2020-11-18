#include <cassert>
#include <vector>

std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &matrix) {
    enum State {
        kUp,
        kDown,
    };

    std::vector<int> ret;
    if (matrix.empty()) {
        return ret;
    }

    int rows = static_cast<int>(matrix.size());
    int cols = static_cast<int>(matrix[0].size());

    int i = 0;
    int j = 0;

    State state = kUp;
    while (true) {
        ret.push_back(matrix[i][j]);

        if (i == rows - 1 && j == cols - 1) {
            break;
        }

        if (state == kUp) {
            --i;
            ++j;
        } else {
            ++i;
            --j;
        }

        if (i < 0 || j >= cols) {
            state = kDown;
            if (i < 0 && j >= cols) {
                i = 1;
                j = cols - 1;
            } else if (i < 0) {
                i = 0;
            } else {
                i = i + 2;
                j = cols - 1;
            }
        } else if (i >= rows || j < 0) {
            state = kUp;
            if (i >= rows && j < 0) {
                i = rows - 1;
                j = 1;
            } else if (i >= rows) {
                i = rows - 1;
                j = j + 2;
            } else {
                j = 0;
            }
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
        auto ret = findDiagonalOrder(matrix);

        std::vector<int> expected{1, 2, 4, 7, 5, 3, 6, 8, 9};
        assert(ret == expected);
    }
    { assert((findDiagonalOrder(std::vector<std::vector<int>>{}) == std::vector<int>{})); }
    {
        std::vector<std::vector<int>> matrix{
            {2, 5},
            {8, 4},
            {0, -1},
        };
        auto ret = findDiagonalOrder(matrix);

        std::vector<int> expected{2, 5, 8, 0, 4, -1};
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {2, 5, 8},
            {4, 0, -1},
        };
        auto ret = findDiagonalOrder(matrix);

        std::vector<int> expected{2, 5, 4, 0, 8, -1};
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3, 4, 5},
        };
        auto ret = findDiagonalOrder(matrix);

        std::vector<int> expected{1, 2, 3, 4, 5};
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1}, {2}, {3}, {4}, {5},
        };
        auto ret = findDiagonalOrder(matrix);

        std::vector<int> expected{1, 2, 3, 4, 5};
        assert(ret == expected);
    }
    return 0;
}
