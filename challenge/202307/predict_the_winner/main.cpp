#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

bool PredictTheWinner(const std::vector<int> &nums) {
    std::function<int(int left, int right)> f;
    f = [&](int left, int right) -> int {
        if (left >= right) {
            return nums[left];
        }

        int left_max = nums[left] - f(left + 1, right);
        int right_max = nums[right] - f(left, right - 1);

        return std::max(left_max, right_max);
    };

    return f(0, nums.size() - 1) >= 0;
}

int main() {
    {
        std::vector<int> nums{1, 5, 2};
        assert(!PredictTheWinner(nums));
    }
    {
        std::vector<int> nums{1, 5, 233, 7};
        assert(PredictTheWinner(nums));
    }
    return 0;
}
