#include <cassert>
#include <vector>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>
#include <cstdio>

int longestIncreasingPath(const std::vector<std::vector<int>> &matrix) {
    std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    std::map<std::pair<int, int>, int> cache;

    int rows = matrix.size();
    int cols = matrix[0].size();

    std::function<int(int row, int col)> f;
    f = [&](int row, int col) {
        const std::pair<int, int> key{row, col};
        if (cache.find(key) != cache.end()) {
            return cache.at(key);
        }

        int ret = 0;
        for (const auto &step : steps) {
            int r = row + step.first;
            int c = col + step.second;

            if (r >= 0 && r < rows && c >= 0 && c < cols && matrix[r][c] > matrix[row][col]) {
                ret = std::max(ret, f(r, c));
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
        std::vector<std::vector<int>> matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
        assert(longestIncreasingPath(matrix) == 4);
    }
    {
        std::vector<std::vector<int>> matrix{{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
        assert(longestIncreasingPath(matrix) == 4);
    }
    {
        std::vector<std::vector<int>> matrix{{1}};
        assert(longestIncreasingPath(matrix) == 1);
    }
    return 0;
}
