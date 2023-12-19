#include <cassert>
#include <vector>

std::vector<std::vector<int>> imageSmoother(const std::vector<std::vector<int>> &img) {
    int rows = img.size();
    int cols = img[0].size();

    std::vector<std::vector<int>> ret(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int count = 0;
            int sum = 0;

            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (i + x >= 0 && i + x < rows && j + y >= 0 && j + y < cols) {
                        ++count;
                        sum += img[i + x][j + y];
                    }
                }
            }

            ret[i][j] = sum / count;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> img{
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
        };
        std::vector<std::vector<int>> expected{
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        auto ret = imageSmoother(img);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> img{
            {100, 200, 100},
            {200, 50, 200},
            {100, 200, 100},

        };
        std::vector<std::vector<int>> expected{
            {137, 141, 137},
            {141, 138, 141},
            {137, 141, 137},
        };
        auto ret = imageSmoother(img);
        assert(ret == expected);
    }
    return 0;
}
