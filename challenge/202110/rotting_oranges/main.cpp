#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>

int orangesRotting(std::vector<std::vector<int>> &grid) {
    std::queue<std::pair<int, int>> q;
    int fresh_oranges = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                ++fresh_oranges;
            }
        }
    }

    q.push({-1, -1});

    int minutes = -1;
    std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        if (pos.first == -1) {
            ++minutes;

            if (!q.empty()) {
                q.push({-1, -1});
            }
        } else {
            for (const auto &step : steps) {
                int row = pos.first + step.first;
                int col = pos.second + step.second;

                if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1) {
                    grid[row][col] = 2;
                    --fresh_oranges;
                    q.push({row, col});
                }
            }
        }
    }

    if (fresh_oranges > 0) {
        return -1;
    }

    return minutes;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1},
        };
        assert(orangesRotting(grid) == 4);
    }
    {
        std::vector<std::vector<int>> grid{
            {2, 1, 1},
            {0, 1, 1},
            {1, 0, 1},
        };
        assert(orangesRotting(grid) == -1);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 2},
        };
        assert(orangesRotting(grid) == 0);
    }
    return 0;
}
