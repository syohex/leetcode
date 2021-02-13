#include <cassert>
#include <vector>
#include <queue>

int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid) {
    struct Data {
        int x;
        int y;
    };

    std::queue<Data> queue;
    if (grid[0][0] == 0) {
        queue.emplace(Data{grid[0][0]});
        grid[0][0] = 1;
    }

    int row_max = grid.size() - 1;
    int col_max = grid[0].size() - 1;
    while (!queue.empty()) {
        Data d = queue.front();
        queue.pop();

        if (d.x == row_max && d.y == col_max) {
            return grid[d.x][d.y];
        }

        std::vector<Data> candidates;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int x = d.x + i;
                int y = d.y + j;
                if (x >= 0 && x <= row_max && y >= 0 && y <= col_max && grid[x][y] == 0) {
                    queue.emplace(Data{x, y});
                    grid[x][y] = grid[d.x][d.y] + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {0, 1},
            {1, 0},
        };
        // clang-format on
        assert(shortestPathBinaryMatrix(grid) == 2);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {0, 0, 0},
            {1, 1, 0},
            {1, 1, 0},
        };
        // clang-format on
        assert(shortestPathBinaryMatrix(grid) == 4);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {1, 0, 0},
            {1, 1, 0},
            {1, 1, 0},
        };
        // clang-format on
        assert(shortestPathBinaryMatrix(grid) == -1);
    }
    return 0;
}
