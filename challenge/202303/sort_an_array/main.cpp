#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

std::vector<int> sortArray(std::vector<int> &nums) {
    std::function<void(size_t left, size_t right)> f;
    f = [&](size_t left, size_t right) {
        if (left == right) {
            return;
        }

        size_t len = right - left + 1;
        size_t half = len / 2;
        size_t left_end = left + half - 1;
        size_t right_start = left + half;
        f(left, left_end);
        f(right_start, right);

        std::vector<int> tmp;
        for (size_t i = left, j = right_start; i <= left_end || j <= right;) {
            if (i > left_end) {
                tmp.push_back(nums[j++]);
            } else if (j > right) {
                tmp.push_back(nums[i++]);
            } else if (nums[i] < nums[j]) {
                tmp.push_back(nums[i++]);
            } else {
                tmp.push_back(nums[j++]);
            }
        }

        for (size_t i = left, j = 0; i <= right; ++i, ++j) {
            nums[i] = tmp[j];
        }
    };

    f(0, nums.size() - 1);
    return nums;
}

int main() {
    {
        std::vector<int> nums{5, 2, 3, 1};
        std::vector<int> expected{1, 2, 3, 5};
        auto ret = sortArray(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{5, 1, 1, 2, 0, 0};
        std::vector<int> expected{0, 0, 1, 1, 2, 5};
        auto ret = sortArray(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{-2, 3, -5};
        std::vector<int> expected{-5, -2, 3};
        auto ret = sortArray(nums);
        assert(ret == expected);
    }

    return 0;
}
