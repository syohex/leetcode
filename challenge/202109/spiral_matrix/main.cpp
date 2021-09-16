#include <cassert>
#include <vector>

std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix) {
    std::vector<int> ret;
    int rows = matrix.size();
    int cols = matrix[0].size();

    enum class Way {
        kRight,
        kDown,
        kLeft,
        kUp,
    };

    int row = 0;
    int col = 0;
    int count = 1;
    int limit = rows * cols;
    Way way = Way::kRight;
    std::vector<std::vector<bool>> checked(rows, std::vector<bool>(cols, false));
    checked[row][col] = true;
    ret.push_back(matrix[row][col]);

    while (count < limit) {
        switch (way) {
        case Way::kRight: {
            if (col == cols - 1 || checked[row][col + 1]) {
                way = Way::kDown;
                row += 1;
            } else {
                col += 1;
            }
            break;
        }
        case Way::kDown: {
            if (row == rows - 1 || checked[row + 1][col]) {
                way = Way::kLeft;
                col -= 1;
            } else {
                row += 1;
            }
            break;
        }
        case Way::kLeft: {
            if (col == 0 || checked[row][col - 1]) {
                way = Way::kUp;
                row -= 1;
            } else {
                col -= 1;
            }
            break;
        }
        case Way::kUp: {
            if (row == 0 || checked[row - 1][col]) {
                way = Way::kRight;
                col += 1;
            } else {
                row -= 1;
            }
            break;
        }
        }

        checked[row][col] = true;
        ret.push_back(matrix[row][col]);
        ++count;
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
        std::vector<int> expected{1, 2, 3, 6, 9, 8, 7, 4, 5};
        auto ret = spiralOrder(matrix);
        assert(expected == ret);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
        };
        std::vector<int> expected{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
        auto ret = spiralOrder(matrix);
        assert(expected == ret);
    }
    return 0;
}