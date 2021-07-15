#include <cassert>
#include <vector>
#include <algorithm>

int triangleNumber(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int len = nums.size();
    int ret = 0;
    for (int i = 0; i < len - 2; ++i) {
        for (int j = i + 1; j < len - 1; ++j) {
            int k = j + 1;
            while (k < len && nums[i] + nums[j] > nums[k]) {
                ++k;
            }

            ret += k - j - 1;
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