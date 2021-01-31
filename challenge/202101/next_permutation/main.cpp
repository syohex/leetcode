#include <cassert>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int> &nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            --j;
        }

        std::swap(nums[i], nums[j]);
    }

    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    {
        std::vector<int> input{1, 2, 3};
        nextPermutation(input);
        assert((input == std::vector<int>{1, 3, 2}));
    }
    {
        std::vector<int> input{3, 2, 1};
        nextPermutation(input);
        assert((input == std::vector<int>{1, 2, 3}));
    }
    {
        std::vector<int> input{1, 1, 5};
        nextPermutation(input);
        assert((input == std::vector<int>{1, 5, 1}));
    }
    {
        std::vector<int> input{1};
        nextPermutation(input);
        assert((input == std::vector<int>{1}));
    }
    return 0;
}
