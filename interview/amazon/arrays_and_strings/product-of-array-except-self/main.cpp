#include <cassert>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
    int product = 1;
    size_t zeros = 0;
    for (auto num : nums) {
        if (num == 0) {
            ++zeros;
            continue;
        }

        product *= num;
    }

    if (zeros >= 2) {
        product = 0;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            nums[i] = product;
        } else {
            if (zeros > 0) {
                nums[i] = 0;
            } else {
                nums[i] = product / nums[i];
            }
        }
    }

    return nums;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        std::vector<int> expected{24, 12, 8, 6};
        auto ret = productExceptSelf(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{0, 0};
        std::vector<int> expected{0, 0};
        auto ret = productExceptSelf(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 0};
        std::vector<int> expected{0, 1};
        auto ret = productExceptSelf(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{0, 1, 2, 3};
        std::vector<int> expected{6, 0, 0, 0};
        auto ret = productExceptSelf(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{0, 3, 2, 0};
        std::vector<int> expected{0, 0, 0, 0};
        auto ret = productExceptSelf(nums);
        assert(ret == expected);
    }
    return 0;
}
