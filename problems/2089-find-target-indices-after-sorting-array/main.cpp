#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> targetIndices(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::vector<int> ret;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        if (nums[i] == target) {
            ret.push_back(i);
        } else if (nums[i] > target) {
            break;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        std::vector<int> expected{1, 2};
        assert(targetIndices(nums, 2) == expected);
    }
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        std::vector<int> expected{3};
        assert(targetIndices(nums, 3) == expected);
    }
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        std::vector<int> expected{4};
        assert(targetIndices(nums, 5) == expected);
    }
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        std::vector<int> expected{};
        assert(targetIndices(nums, 4) == expected);
    }
    return 0;
}