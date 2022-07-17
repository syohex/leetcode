#include <cassert>
#include <functional>
#include <algorithm>
#include <cstdint>
#include <cstring>

int kInversePairs(int n, int k) {
    constexpr std::int64_t MOD = 1'000'000'007;
    int cache[1001][1001];
    std::memset(cache, -1, sizeof(cache));

    std::function<std::int64_t(int n, int k)> f;
    f = [&](int n, int k) -> std::int64_t {
        if (n <= 0) {
            return 0;
        }
        if (k <= 0) {
            return 1;
        }
        if (cache[n][k] != -1) {
            return cache[n][k];
        }

        std::int64_t ret = 0;
        int len = std::min(n - 1, k);
        for (int i = 0; i <= len; ++i) {
            ret = (ret + f(n - 1, k - i)) % MOD;
        }

        cache[n][k] = ret;
        return ret;
    };

    return f(n, k);
}

int main() {
    assert(kInversePairs(3, 0) == 1);
    assert(kInversePairs(3, 1) == 2);
    return 0;
}
