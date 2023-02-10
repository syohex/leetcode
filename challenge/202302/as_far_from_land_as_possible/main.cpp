#include <cassert>
#include <vector>
#include <queue>
#include <cstdio>

int maxDistance(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> visited(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    if (q.size() == 0 || q.size() == n * n) {
        return -1;
    }

    std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int ret = -1;
    while (!q.empty()) {
        size_t len = q.size();
        for (size_t i = 0; i < len; ++i) {
            auto [row, col] = q.front();
            q.pop();

            for (const auto &[i, j] : steps) {
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0 && visited[r][c] == 0) {
                    q.push({r, c});
                    visited[r][c] = 1;
                }
            }
        }

        ++ret;
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1},
        };
        int ret = maxDistance(grid);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        int ret = maxDistance(grid);
        assert(ret == 4);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
        };
        int ret = maxDistance(grid);
        assert(ret == -1);
    }
    return 0;
}
