#include <cassert>
#include <vector>
#include <cstdio>

int maxOperations(const std::vector<int> &nums) {
    int len = nums.size();
    if (len < 2) {
        return 0;
    }

    int sum = nums[0] + nums[1];
    int ret = 1;
    for (int i = 2; i + 1 < len; i += 2) {
        if (nums[i] + nums[i + 1] != sum) {
            break;
        }

        ++ret;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 2, 1, 4, 5};
        int ret = maxOperations(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{3, 2, 6, 1, 4};
        int ret = maxOperations(nums);
        assert(ret == 1);
    }
    return 0;
}
