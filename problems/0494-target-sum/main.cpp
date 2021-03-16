#include <cassert>
#include <vector>
#include <functional>
#include <map>

int findTargetSumWays(const std::vector<int> &nums, int S) {
    std::map<std::pair<size_t, int>, int> cache;

    std::function<int(const std::vector<int> &nums, int target, size_t pos, int acc)> f;
    f = [&f, &cache](const std::vector<int> &nums, int target, size_t pos, int acc) -> int {
        if (pos >= nums.size()) {
            return acc == target ? 1 : 0;
        }

        int ret1, ret2;
        auto pair1 = std::make_pair(pos + 1, acc + nums[pos]);
        if (cache.find(pair1) != cache.end()) {
            ret1 = cache[pair1];
        } else {
            ret1 = f(nums, target, pos + 1, acc + nums[pos]);
            cache[pair1] = ret1;
        }

        auto pair2 = std::make_pair(pos + 1, acc - nums[pos]);
        if (cache.find(pair2) != cache.end()) {
            ret2 = cache[pair2];
        } else {
            ret2 = f(nums, target, pos + 1, acc - nums[pos]);
            cache[pair2] = ret2;
        }

        return ret1 + ret2;
    };

    return f(nums, S, 0, 0);
}

int main() {
    {
        std::vector<int> nums{1, 1, 1, 1, 1};
        assert(findTargetSumWays(nums, 3) == 5);
    }
    return 0;
}
