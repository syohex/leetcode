#include <cassert>
#include <functional>
#include <tuple>
#include <map>

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    std::map<std::tuple<int, int, int>, long> cache;
    std::function<long(int row, int col, int moves)> f;
    f = [&f, &m, &n, &maxMove, &cache](int row, int col, int moves) -> long {
        constexpr long MOD = 1'000'000'000 + 7;
        if (moves > maxMove) {
            return 0;
        }
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }

        std::tuple<int, int, int> key{row, col, moves};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        long v1 = f(row - 1, col, moves + 1) % MOD;
        long v2 = f(row, col + 1, moves + 1) % MOD;
        long v3 = f(row + 1, col, moves + 1) % MOD;
        long v4 = f(row, col - 1, moves + 1) % MOD;
        long v = (v1 + v2 + v3 + v4) % MOD;
        cache[key] = v;
        return v;
    };

    return f(startRow, startColumn, 0);
}

int main() {
    assert(findPaths(2, 2, 2, 0, 0) == 6);
    assert(findPaths(1, 3, 3, 0, 1) == 12);
    return 0;
}
