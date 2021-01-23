#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>> &mat) {
    struct Pos {
        int x;
        int y;
    };

    std::vector<Pos> v;
    int row_limit = mat.size();
    int col_limit = mat[0].size();
    for (int i = mat[0].size() - 1; i >= 0; --i) {
        v.emplace_back(Pos{0, i});
    }
    for (int i = 1; i < row_limit; ++i) {
        v.emplace_back(Pos{i, 0});
    }

    for (const auto &pos : v) {
        if (pos.x + 1 >= row_limit || pos.y + 1 >= col_limit) {
            continue;
        }

        int limit = std::min(row_limit - pos.x, col_limit - pos.y);
        for (int i = 0; i < limit - 1; ++i) {
            for (int j = i + 1; j < limit; ++j) {
                if (mat[pos.x + i][pos.y + i] > mat[pos.x + j][pos.y + j]) {
                    std::swap(mat[pos.x + i][pos.y + i], mat[pos.x + j][pos.y + j]);
                }
            }
        }
    }

    return mat;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> mat {
            {3, 3, 1, 1},
            {2, 2, 1, 2},
            {1, 1, 1, 2},
        };
        std::vector<std::vector<int>> expected {
            {1, 1, 1, 1},
            {1, 2, 2, 2},
            {1, 2, 3, 3},
        };
        // clang-format on
        auto ret = diagonalSort(mat);
        assert(ret == expected);
    }
    return 0;
}
