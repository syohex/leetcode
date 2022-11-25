#include <cassert>
#include <vector>

int equalTriplets(const std::vector<int> &nums) {
    int len = nums.size();
    int ret = 0;
    for (int i = 0; i < len - 2; ++i) {
        for (int j = i + 1; j < len - 1; ++j) {
            if (nums[i] == nums[j]) {
                continue;
            }

            for (int k = j + 1; k < len; ++k) {
                if (nums[j] == nums[k] || nums[i] == nums[k]) {
                    continue;
                }

                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 4, 2, 4, 3};
        int ret = equalTriplets(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{0, 0, 0, 0, 0};
        int ret = equalTriplets(nums);
        assert(ret == 0);
    }
    return 0;
}
