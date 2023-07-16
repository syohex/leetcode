#include <cassert>
#include <vector>
#include <cstddef>

int sumOfSquares(const std::vector<int> &nums) {
    int ret = 0;
    int len = nums.size();
    for (int i = 1; i <= len; ++i) {
        if (len % i == 0) {
            ret += nums[i - 1] * nums[i - 1];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = sumOfSquares(nums);
        assert(ret == 21);
    }
    {
        std::vector<int> nums{2, 7, 1, 19, 18, 3};
        int ret = sumOfSquares(nums);
        assert(ret == 63);
    }
    return 0;
}
