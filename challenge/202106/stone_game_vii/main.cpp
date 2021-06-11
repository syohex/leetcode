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

    std::vector<std::vector<int>> cache(len, std::vector<int>(len, -1));
    std::function<int(int start, int end)> f;
    f = [&f, &acc, &cache](int start, int end) -> int {
        if (start == end) {
            return 0;
        }

        if (cache[start][end] != -1) {
            return cache[start][end];
        }

        int remove_first = acc[end + 1] - acc[start + 1];
        int remove_last = acc[end] - acc[start];

        int v1 = remove_first - f(start + 1, end);
        int v2 = remove_last - f(start, end - 1);
        int ret = std::max(v1, v2);

        cache[start][end] = ret;
        return ret;
    };

    return std::abs(f(0, len - 1));
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
