#include <cassert>
#include <vector>
#include <set>

std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix) {
    enum State {
        kRight,
        kDown,
        kLeft,
        kUp,
    };

    std::vector<int> ret;
    std::set<std::vector<int>> s;

    int rows = static_cast<int>(matrix.size());
    int cols = static_cast<int>(matrix[0].size());

    State state = kRight;
    int row = 0;
    int col = 0;

    while (true) {
        ret.push_back(matrix[row][col]);
        s.emplace(std::vector<int>{row, col});

        switch (state) {
        case kRight: {
            std::vector<int> next_right{row, col + 1};

            if (next_right[1] >= cols || s.find(next_right) != s.end()) {
                state = kDown;
                std::vector<int> next_down{row + 1, col};
                if (next_down[0] >= rows) {
                    goto end;
                }

                if (s.find(next_down) != s.end()) {
                    goto end;
                }

                row += 1;
            } else {
                col += 1;
            }
            break;
        }
        case kDown: {
            std::vector<int> next_down{row + 1, col};

            if (next_down[0] >= rows || s.find(next_down) != s.end()) {
                state = kLeft;
                std::vector<int> next_left{row, col - 1};
                if (next_left[1] < 0) {
                    goto end;
                }

                if (s.find(next_left) != s.end()) {
                    goto end;
                }

                col -= 1;
            } else {
                row += 1;
            }
            break;
        }
        case kLeft: {
            std::vector<int> next_left{row, col - 1};

            if (next_left[1] < 0 || s.find(next_left) != s.end()) {
                state = kUp;
                std::vector<int> next_up{row - 1, col};
                if (next_left[0] < 0) {
                    goto end;
                }

                if (s.find(next_up) != s.end()) {
                    goto end;
                }

                row -= 1;
            } else {
                col -= 1;
            }
            break;
        }
        case kUp: {
            std::vector<int> next_up{row - 1, col};

            if (next_up[0] < 0 || s.find(next_up) != s.end()) {
                state = kRight;
                std::vector<int> next_right{row, col + 1};
                if (next_right[1] >= cols) {
                    goto end;
                }

                if (s.find(next_right) != s.end()) {
                    goto end;
                }

                col += 1;
            } else {
                row -= 1;
            }
            break;
        }
        }
    }

end:
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
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
        };
        std::vector<int> expected{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

        auto ret = spiralOrder(matrix);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3},
        };
        std::vector<int> expected{1, 2, 3};

        auto ret = spiralOrder(matrix);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1},
            {4},
            {7},
        };
        std::vector<int> expected{1, 4, 7};

        auto ret = spiralOrder(matrix);
        assert(ret == expected);
    }
    return 0;
}
