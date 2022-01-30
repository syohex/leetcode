#include <cassert>
#include <vector>
#include <algorithm>

void rotate(std::vector<int> &nums, int k) {
    k %= nums.size();

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
        std::vector<int> expected{5, 6, 7, 1, 2, 3, 4};
        rotate(nums, 3);
        assert(nums == expected);
    }
    {
        std::vector<int> nums{-1, -100, 3, 99};
        std::vector<int> expected{3, 99, -1, -100};
        rotate(nums, 2);
        assert(nums == expected);
    }
    return 0;
}
