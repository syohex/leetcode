#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
#include <cmath>

int stoneGameVII(const std::vector<int> &stones) {
    int len = stones.size();
    std::vector<int> acc(len + 1, 0);
    for (int i = 0; i < len; ++i) {
        acc[i + 1] = acc[i] + stones[i];
    }

    std::map<std::tuple<int, int, bool>, int> cache;
    std::function<int(int start, int end, bool is_alice)> f;
    f = [&f, &acc, &cache](int start, int end, bool is_alice) -> int {
        if (start == end) {
            return 0;
        }

        std::tuple<int, int, bool> key(start, end, is_alice);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int remove_first = acc[end + 1] - acc[start + 1];
        int remove_last = acc[end] - acc[start];

        int ret;
        if (is_alice) {
            int v1 = f(start + 1, end, false) + remove_first;
            int v2 = f(start, end - 1, false) + remove_last;
            ret = std::max(v1, v2);
        } else {
            int v1 = f(start + 1, end, true) - remove_first;
            int v2 = f(start, end - 1, true) - remove_last;
            ret = std::min(v1, v2);
        }

        cache[key] = ret;
        return ret;
    };

    return std::abs(f(0, len - 1, true));
}

int main() {
    {
        std::vector<int> stones{5, 3, 1, 4, 2};
        assert(stoneGameVII(stones) == 6);
    }
    {
        std::vector<int> stones{7, 90, 5, 1, 100, 10, 10, 2};
        assert(stoneGameVII(stones) == 122);
    }
    return 0;
}
