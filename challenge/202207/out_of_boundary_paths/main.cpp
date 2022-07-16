#include <cassert>
#include <functional>
#include <map>
#include <cstdint>
#include <cstring>

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    constexpr std::int64_t MOD = 1'000'000'007;
    std::int64_t cache[51][51][51];
    std::memset(cache, -1, sizeof(cache));

    std::function<std::int64_t(int row, int col, int moves)> f;
    f = [&](int row, int col, int moves) -> std::int64_t {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        if (moves == 0) {
            return 0;
        }

        if (cache[row][col][moves] != -1) {
            return cache[row][col][moves];
        }

        std::int64_t ret = 0;
        ret += f(row - 1, col, moves - 1);
        ret += f(row, col - 1, moves - 1);
        ret += f(row + 1, col, moves - 1);
        ret += f(row, col + 1, moves - 1);

        cache[row][col][moves] = ret % MOD;
        return cache[row][col][moves];
    };

    return f(startRow, startColumn, maxMove);
}

int main() {
    {
        int ret = findPaths(2, 2, 2, 0, 0);
        assert(ret == 6);
    }
    {
        int ret = findPaths(1, 3, 3, 0, 1);
        assert(ret == 12);
    }
    return 0;
}
