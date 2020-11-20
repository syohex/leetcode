#include <cassert>
#include <vector>
#include <map>

std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::map<int, int> m;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int v = target - nums[i];
        if (m.find(v) != m.end()) {
            return std::vector<int>{m[v], i};
        }

        m[nums[i]] = i;
    }
    return std::vector<int>{};
}

int main() {
    {
        std::vector<int> nums{2, 7, 11, 15};
        std::vector<int> expected{0, 1};
        auto ret = twoSum(nums, 9);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{3, 2, 4};
        std::vector<int> expected{1, 2};
        auto ret = twoSum(nums, 6);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{3, 3};
        std::vector<int> expected{0, 1};
        auto ret = twoSum(nums, 6);
        assert(ret == expected);
    }
    return 0;
}
