#include <cassert>
#include <vector>
#include <cmath>
#include <cstdio>

std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        size_t idx = std::abs(nums[i]) - 1;
        if (nums[idx] > 0) {
            nums[idx] *= -1;
        }
    }

    std::vector<int> ret;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            ret.push_back(i + 1);
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{4, 3, 2, 7, 8, 2, 3, 1};
        auto ret = findDisappearedNumbers(input);
        assert((ret == std::vector<int>{5, 6}));
    }
    return 0;
}
