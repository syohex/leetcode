#include <cassert>
#include <vector>

int triangleNumber(const std::vector<int> &nums) {
    int len = nums.size();
    int ret = 0;
    for (int i = 0; i < len - 2; ++i) {
        for (int j = i + 1; j < len - 1; ++j) {
            for (int k = j + 1; k < len; ++k) {
                if (nums[i] + nums[j] > nums[k] && nums[j] + nums[k] > nums[i] && nums[i] + nums[k] > nums[j]) {
                    ++ret;
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 2, 3, 4};
        assert(triangleNumber(nums) == 3);
    }
    {
        std::vector<int> nums{4, 2, 3, 4};
        assert(triangleNumber(nums) == 4);
    }
    return 0;
}