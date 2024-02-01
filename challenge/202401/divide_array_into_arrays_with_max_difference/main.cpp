#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> ret;
    for (size_t i = 0; i < nums.size(); i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            return {};
        }

        ret.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 4, 8, 7, 9, 3, 5, 1};
        std::vector<std::vector<int>> expected{
            {1, 1, 3},
            {3, 4, 5},
            {7, 8, 9},
        };
        auto ret = divideArray(nums, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 3, 3, 2, 7, 3};
        auto ret = divideArray(nums, 3);
        assert(ret.empty());
    }
    return 0;
}
