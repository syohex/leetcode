#include <cassert>
#include <vector>
#include <functional>

int rob(const std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    int prev = 0, cur = 0;
    for (int num : nums) {
        int tmp = cur;
        int sum = prev + num;
        cur = sum > cur ? sum : cur;
        prev = tmp;
    }

    return cur;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 1};
        assert(rob(input) == 4);
    }
    {
        std::vector<int> input{2, 7, 9, 3, 1};
        assert(rob(input) == 12);
    }
    {
        std::vector<int> input{2, 1, 1, 2};
        assert(rob(input) == 4);
    }
    return 0;
}
