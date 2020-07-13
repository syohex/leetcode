#include <cassert>
#include <vector>

int oddCells(int n, int m, const std::vector<std::vector<int>> &indices) {
    std::vector<std::vector<int>> mat(n);
    for (int i = 0; i < n; ++i) {
        mat[i].resize(m);
    }

    for (const auto &index : indices) {
        for (int i = 0; i < m; ++i) {
            ++mat[index[0]][i];
        }
        for (int i = 0; i < n; ++i) {
            ++mat[i][index[1]];
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((mat[i][j] & 0x1) == 0x1) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> indices{
            {0, 1},
            {1, 1},
        };
        assert(oddCells(2, 3, indices) == 6);
    }
    {
        std::vector<std::vector<int>> indices{
            {1, 1},
            {0, 0},
        };
        assert(oddCells(2, 2, indices) == 0);
    }
    return 0;
}
