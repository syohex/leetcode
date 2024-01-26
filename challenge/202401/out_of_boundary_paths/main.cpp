#include <cassert>
#include <functional>
#include <map>
#include <cstdint>

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    constexpr int MOD = 1'000'000'007;
    using Key = std::tuple<int, int, int>;

    std::function<int64_t(int row, int col, int moves, std::map<Key, int> &cache)> f;
    f = [&](int row, int col, int moves, std::map<Key, int> &cache) -> int64_t {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        if (moves == 0) {
            return 0;
        }

        Key k{row, col, moves};
        if (cache.find(k) != cache.end()) {
            return cache[k];
        }

        int64_t ret = 0;
        ret += f(row - 1, col, moves - 1, cache);
        ret += f(row, col - 1, moves - 1, cache);
        ret += f(row + 1, col, moves - 1, cache);
        ret += f(row, col + 1, moves - 1, cache);

        cache[k] = ret % MOD;
        return cache[k];
    };

    std::map<Key, int> cache;
    return static_cast<int>(f(startRow, startColumn, maxMove, cache));
}

int main() {
    assert(findPaths(2, 2, 2, 0, 0) == 6);
    assert(findPaths(1, 3, 3, 0, 1) == 12);
    return 0;
}
