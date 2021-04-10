#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>

int longestIncreasingPath(const std::vector<std::vector<int>> &matrix) {
    std::map<std::vector<int>, int> cache;
    const std::vector<std::vector<int>> steps{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int rows = matrix.size();
    int cols = matrix[0].size();

    std::function<int(int x, int y)> f;
    f = [&](int x, int y) -> int {
        const std::vector<int> key{x, y};
        if (cache.find(key) != cache.end()) {
            return cache.at(key);
        }

        int ret = 0;
        for (const auto &step : steps) {
            int new_x = x + step[0];
            int new_y = y + step[1];

            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && matrix[new_x][new_y] > matrix[x][y]) {
                ret = std::max(ret, f(new_x, new_y));
            }
        }

        cache[key] = ret + 1;
        return cache[key];
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ret = std::max(ret, f(i, j));
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1},
        };
        assert(longestIncreasingPath(matrix) == 4);
    }
    {
        std::vector<std::vector<int>> matrix{
            {3, 4, 5},
            {3, 2, 6},
            {2, 2, 1},
        };
        assert(longestIncreasingPath(matrix) == 4);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1},
        };
        assert(longestIncreasingPath(matrix) == 1);
    }
    return 0;
}