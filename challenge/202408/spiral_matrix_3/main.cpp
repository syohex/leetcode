#include <cassert>
#include <vector>

std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    std::vector<std::pair<int, int>> steps{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::size_t limit = rows * cols;

    std::vector<std::vector<int>> ret;
    int row = rStart;
    int col = cStart;

    int direction = 0;
    int step = 1;
    while (ret.size() < limit) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < step; ++j) {
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    ret.push_back({row, col});
                }

                row += steps[direction].first;
                col += steps[direction].second;
            }

            direction = (direction + 1) % 4;
        }

        ++step;
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> expected{{0, 0}, {0, 1}, {0, 2}, {0, 3}};
        auto ret = spiralMatrixIII(1, 4, 0, 0);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> expected{{1, 4}, {1, 5}, {2, 5}, {2, 4}, {2, 3}, {1, 3}, {0, 3}, {0, 4}, {0, 5}, {3, 5},
                                               {3, 4}, {3, 3}, {3, 2}, {2, 2}, {1, 2}, {0, 2}, {4, 5}, {4, 4}, {4, 3}, {4, 2},
                                               {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}};
        auto ret = spiralMatrixIII(5, 6, 1, 4);
        assert(ret == expected);
    }
    return 0;
}