#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <limits>

int maxDistance(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    std::set<std::pair<int, int>> lands;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                lands.insert({i, j});
            }
        }
    }

    if (lands.empty() || lands.size() == n * n) {
        return -1;
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int distance = std::numeric_limits<int>::max();
            for (const auto &[row, col] : lands) {
                distance = std::min(distance, std::abs(i - row) + std::abs(j - col));
            }
            ret = std::max(ret, distance);
        }
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
