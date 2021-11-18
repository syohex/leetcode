#include <cassert>
#include <vector>

std::vector<int> findDisappearedNumbers(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> tmp(len, 0);
    for (int n : nums) {
        --tmp[n - 1];
    }

    std::vector<int> ret;
    for (int i = 0; i < len; ++i) {
        if (tmp[i] == 0) {
            ret.push_back(i + 1);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
        std::vector<int> expected{5, 6};
        assert(findDisappearedNumbers(nums) == expected);
    }
    {
        std::vector<int> nums{1, 1};
        std::vector<int> expected{2};
        assert(findDisappearedNumbers(nums) == expected);
    }
    return 0;
}
