#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

std::vector<int> sortArray(const std::vector<int> &nums) {
    std::function<std::vector<int>(const std::vector<int> &nums)> f;
    f = [&](const std::vector<int> &nums) -> std::vector<int> {
        if (nums.size() == 1) {
            return nums;
        }

        size_t len = nums.size();
        size_t half = len / 2;
        auto left = f(std::vector<int>(nums.begin(), nums.begin() + half));
        auto right = f(std::vector<int>(nums.begin() + half, nums.end()));

        std::vector<int> ret;
        for (size_t i = 0, j = 0; i < left.size() || j < right.size();) {
            if (i >= left.size()) {
                ret.push_back(right[j]);
                ++j;
            } else if (j >= right.size()) {
                ret.push_back(left[i]);
                ++i;
            } else if (left[i] < right[j]) {
                ret.push_back(left[i]);
                ++i;
            } else {
                ret.push_back(right[j]);
                ++j;
            }
        }

        return ret;
    };

    return f(nums);
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
