#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <cstdio>

int combinationSum4(const std::vector<int> &nums, int target) {
    std::function<int(int, std::map<int, int> &)> f;
    f = [&](int target, std::map<int, int> &cache) -> int {
        if (target == 0) {
            return 1;
        }

        if (cache.find(target) != cache.end()) {
            return cache[target];
        }

        int ret = 0;
        for (int num : nums) {
            if (target - num >= 0) {
                ret += f(target - num, cache);
            }
        }

        cache[target] = ret;
        return ret;
    };

    std::map<int, int> cache;
    return f(target, cache);
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        int ret = combinationSum4(nums, 4);
        assert(ret == 7);
    }
    {
        std::vector<int> nums{9};
        int ret = combinationSum4(nums, 3);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{1,2,3};
        int ret = combinationSum4(nums, 32);
        assert(ret == 0);
    }
    return 0;
}
