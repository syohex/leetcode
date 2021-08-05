#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <tuple>

bool stoneGame(const std::vector<int> &piles) {
    using key_type = std::tuple<int, int>;

    int len = piles.size();
    std::map<key_type, int> cache;
    std::function<int(int left, int right)> f;
    f = [&f, &piles, &cache, &len](int left, int right) -> int {
        if (left >= len || right < 0) {
            return 0;
        }

        key_type key{left, right};
        if (cache.find(key) != cache.end()) {
            return cache.at(key);
        }

        int left_score = piles[left] + std::min(f(left + 2, right), f(left + 1, right - 1));
        int right_score = piles[right] + std::min(f(left, right - 2), f(left + 1, right - 1));

        cache[key] = std::max(left_score, right_score);
        return cache[key];
    };

    int alex = f(0, len - 1);
    int sum = 0;
    for (int pile : piles) {
        sum += pile;
    }

    return alex > sum - alex;
}

int main() {
    {
        std::vector<int> piles{5, 3, 4, 5};
        assert(stoneGame(piles));
    }
    {
        std::vector<int> piles{3, 2, 10, 4};
        assert(stoneGame(piles));
    }
    return 0;
}
