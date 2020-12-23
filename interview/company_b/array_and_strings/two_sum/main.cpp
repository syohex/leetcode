#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::map<int, std::vector<int>> m;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        m[nums[i]].push_back(i);
    }

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int diff = target - nums[i];
        if (m.find(diff) != m.end()) {
            for (const auto index : m[diff]) {
                if (index != i) {
                    return std::vector<int>{std::min(i, index), std::max(i, index)};
                }
            }
        }
    }

    assert(!"never reach here");
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
