#include <cassert>
#include <vector>

std::vector<int> shuffle(const std::vector<int> &nums, int n) {
    std::vector<int> ret(2 * n);
    for (int i = 0, j = 0; i < n; i += 1, j += 2) {
        ret[j] = nums[i];
        ret[j + 1] = nums[n + i];
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 5, 1, 3, 4, 7};
        std::vector<int> expected{2, 3, 5, 4, 1, 7};
        auto ret = shuffle(nums, 3);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 4, 3, 2, 1};
        std::vector<int> expected{1, 4, 2, 3, 3, 2, 4, 1};
        auto ret = shuffle(nums, 4);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 1, 2, 2};
        std::vector<int> expected{1, 2, 1, 2};
        auto ret = shuffle(nums, 2);
        assert(ret == expected);
    }
    return 0;
}
