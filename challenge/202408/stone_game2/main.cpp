#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

int stoneGameII(const std::vector<int> &piles) {
    std::map<std::tuple<bool, int, int>, int> cache;
    int len = piles.size();

    std::function<int(bool is_alice, int i, int m)> f;
    f = [&](bool is_alice, int i, int m) -> int {
        if (i >= len) {
            return 0;
        }

        const std::tuple<bool, int, int> key{is_alice, i, m};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int limit = std::min(2 * m, len - i);
        int ret = is_alice ? -1 : 1'000'000'000;
        int score = 0;
        for (int j = 0; j < limit; ++j) {
            score += piles[i + j];

            int next_m = std::max(m, j + 1);
            if (is_alice) {
                ret = std::max(ret, score + f(false, i + j + 1, next_m));
            } else {
                ret = std::min(ret, f(true, i + j + 1, next_m));
            }
        }

        cache[key] = ret;
        return ret;
    };

    return f(true, 0, 1);
}

int main() {
    {
        std::vector<int> piles{2, 7, 9, 4, 4};
        int ret = stoneGameII(piles);
        assert(ret == 10);
    }
    {
        std::vector<int> piles{1, 2, 3, 4, 5, 100};
        int ret = stoneGameII(piles);
        assert(ret == 104);
    }
    return 0;
}
