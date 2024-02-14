#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> rearrangeArray(const std::vector<int> &nums) {
    size_t positive_pos = 0;
    size_t negative_pos = 0;
    bool is_positive = true;

    std::vector<int> ret;
    size_t len = nums.size();
    while (ret.size() < len) {
        if (is_positive) {
            while (positive_pos < len) {
                if (nums[positive_pos] >= 0) {
                    ret.push_back(nums[positive_pos]);
                    ++positive_pos;
                    break;
                }
                ++positive_pos;
            }
        } else {
            while (negative_pos < len) {
                if (nums[negative_pos] < 0) {
                    ret.push_back(nums[negative_pos]);
                    ++negative_pos;
                    break;
                }
                ++negative_pos;
            }
        }

        is_positive = !is_positive;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 1, -2, -5, 2, -4};
        std::vector<int> expected{3, -2, 1, -5, 2, -4};
        auto ret = rearrangeArray(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{-1, 1};
        std::vector<int> expected{1, -1};
        auto ret = rearrangeArray(nums);
        assert(ret == expected);
    }
    return 0;
}
