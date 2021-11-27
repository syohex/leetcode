#include <cassert>
#include <vector>
#include <set>

std::vector<int> productExceptSelf(const std::vector<int> &nums) {
    std::set<size_t> zeros;

    int mul = 1;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            zeros.insert(i);
        } else {
            mul *= nums[i];
        }
    }

    if (zeros.size() >= 2) {
        return std::vector<int>(nums.size(), 0);
    }

    std::vector<int> ret;
    if (zeros.empty()) {
        for (size_t i = 0; i < nums.size(); ++i) {
            ret.push_back(mul / nums[i]);
        }

        return ret;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        if (zeros.find(i) != zeros.end()) {
            ret.push_back(mul);
        } else {
            ret.push_back(0);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        std::vector<int> expected{24, 12, 8, 6};
        assert(productExceptSelf(nums) == expected);
    }
    {
        std::vector<int> nums{-1, 1, 0, -3, 3};
        std::vector<int> expected{0, 0, 9, 0, 0};
        assert(productExceptSelf(nums) == expected);
    }
    {
        std::vector<int> nums{0, 1, 0, -3, 3};
        std::vector<int> expected{0, 0, 0, 0, 0};
        assert(productExceptSelf(nums) == expected);
    }
    return 0;
}