#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int countSubIslands(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2) {
    int rows = grid1.size();
    int cols = grid1[0].size();
    std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    const auto f = [&](int row, int col) -> bool {
        std::vector<std::pair<int, int>> q;
        q.push_back({row, col});

        bool ret = true;
        while (!q.empty()) {
            auto [r, c] = q.back();
            q.pop_back();

            grid2[r][c] = 0;

            if (grid1[r][c] == 0) {
                ret = false;
            }

            for (const auto &[x, y] : steps) {
                int new_x = r + x;
                int new_y = c + y;

                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && grid2[new_x][new_y] == 1) {
                    q.push_back({new_x, new_y});
                }
            }
        }

        return ret;
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid2[i][j] == 1 && f(i, j)) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid1{
            {1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1},
        };
        std::vector<std::vector<int>> grid2{
            {1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0},
        };

        int ret = countSubIslands(grid1, grid2);
        assert(ret == 3);
    }
    {
        std::vector<std::vector<int>> grid1{
            {1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 0, 1, 0, 1},
        };
        std::vector<std::vector<int>> grid2{
            {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 1, 0, 1, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1},
        };

        int ret = countSubIslands(grid1, grid2);
        assert(ret == 2);
    }
    return 0;
}