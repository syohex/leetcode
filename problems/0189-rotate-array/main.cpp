#include <cassert>
#include <vector>

void rotate(std::vector<int> &nums, int k) {
    if (k == 0) {
        return;
    }

    std::vector<int> tmp(nums.size());
    size_t start = nums.size() - (k % nums.size());
    for (size_t i = start, j = 0; j < nums.size(); ++i, ++j) {
        tmp[j] = nums[i % nums.size()];
    }

    nums.assign(tmp.begin(), tmp.end());
    return;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 4, 5, 6, 7};
        rotate(input, 3);
        assert((input == std::vector<int>{5, 6, 7, 1, 2, 3, 4}));
    }
    {
        std::vector<int> input{-1, -100, 3, 99};
        rotate(input, 2);
        assert((input == std::vector<int>{3, 99, -1, -100}));
    }
    {
        std::vector<int> input{1, 2, 3};
        rotate(input, 4);
        assert((input == std::vector<int>{3, 1, 2}));
    }
    return 0;
}
