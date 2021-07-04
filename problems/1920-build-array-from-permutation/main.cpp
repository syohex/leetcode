#include <cassert>
#include <vector>

std::vector<int> buildArray(const std::vector<int> &nums) {
    std::vector<int> ret(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
        ret[i] = nums[nums[i]];
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 2, 1, 5, 3, 4};
        std::vector<int> expected{0, 1, 2, 4, 5, 3};
        auto ret = buildArray(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{5, 0, 1, 2, 3, 4};
        std::vector<int> expected{4, 5, 0, 1, 2, 3};
        auto ret = buildArray(nums);
        assert(ret == expected);
    }
    return 0;
}
