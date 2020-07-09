#include <cassert>
#include <vector>
#include <climits>

int maxSubArray(const std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }

    int max = nums[0];
    int sum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (sum + nums[i] < nums[i]) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }

        if (max < sum) {
            max = sum;
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        assert(maxSubArray(input) == 6);
    }
    {
        std::vector<int> input{-1, -2};
        assert(maxSubArray(input) == -1);
    }
    return 0;
}
