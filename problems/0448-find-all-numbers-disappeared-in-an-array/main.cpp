#include <cassert>
#include <vector>

std::vector<int> findDisappearedNumbers(const std::vector<int> &nums) {
    std::vector<int> tmp(nums.size(), 1);
    for (size_t i = 0; i < nums.size(); ++i) {
        tmp[nums[i] - 1] = 0;
    }

    std::vector<int> ret;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (tmp[i] == 1) {
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
