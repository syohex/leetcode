#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int minOperations(const std::vector<int> &nums, int x) {
    std::vector<int> acc_left(nums.size() + 1, 0);
    std::vector<int> acc_right(nums.size() + 1, 0);

    for (size_t i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
        acc_left[i + 1] = acc_left[i] + nums[i];
        acc_right[i + 1] = acc_right[i] + nums[j];
    }

    size_t ret = SIZE_MAX;
    for (size_t i = 0; i < acc_left.size(); ++i) {
        if (acc_left[i] > x) {
            break;
        }

        for (size_t j = 0; j < acc_right.size() - i; ++j) {
            int sum = acc_left[i] + acc_right[j];
            if (sum > x) {
                break;
            }

            if (sum == x) {
                ret = std::min(ret, i + j);
            }
        }
    }

    return ret == SIZE_MAX ? -1 : static_cast<int>(ret);
}

int main() {
    {
        std::vector<int> nums{1, 1, 4, 2, 3};
        assert(minOperations(nums, 5) == 2);
    }
    {
        std::vector<int> nums{5, 6, 7, 8, 9};
        assert(minOperations(nums, 4) == -1);
    }
    {
        std::vector<int> nums{3, 2, 20, 1, 1, 3};
        assert(minOperations(nums, 10) == 5);
    }
    {
        std::vector<int> nums{1, 1};
        assert(minOperations(nums, 3) == -1);
    }
    return 0;
}
