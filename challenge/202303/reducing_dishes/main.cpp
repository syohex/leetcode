#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

int maxSatisfaction(std::vector<int> &satisfaction) {
    std::sort(satisfaction.begin(), satisfaction.end());

    int len = satisfaction.size();
    std::vector<std::vector<int>> cache(len, std::vector<int>(len + 1, -1));

    std::function<int(int index, int time)> f;
    f = [&](int index, int time) -> int {
        if (index >= len) {
            return 0;
        }

        if (cache[index][time] != -1) {
            return cache[index][time];
        }

        int64_t ret1 = satisfaction[index] * time + f(index + 1, time + 1);
        int64_t ret2 = f(index + 1, time);
        int64_t ret = std::max(ret1, ret2);
        cache[index][time] = ret;
        return ret;
    };

    return f(0, 1);
}

int main() {
    {
        std::vector<int> satisfaction{-1, -8, 0, 5, -9};
        int ret = maxSatisfaction(satisfaction);
        assert(ret == 14);
    }
    {
        std::vector<int> satisfaction{4, 3, 2};
        int ret = maxSatisfaction(satisfaction);
        assert(ret == 20);
    }
    {
        std::vector<int> satisfaction{-1, -4, -5};
        int ret = maxSatisfaction(satisfaction);
        assert(ret == 0);
    }
    return 0;
}
