#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::map<int, std::vector<int>> m;

    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        m[nums[i]].push_back(i);
    }

    for (int i = 0; i < len; ++i) {
        int diff = target - nums[i];
        if (m.find(diff) != m.end()) {
            const auto &indexes = m[diff];
            if (indexes[0] == i) {
                if (indexes.size() == 1) {
                    continue;
                }
                return {std::min(i, indexes[1]), std::max(i, indexes[1])};
            }

            return {std::min(i, indexes[0]), std::max(i, indexes[0])};
        }
    }

    // never reach here
    return {-1, -1};
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
