#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

void rotate(std::vector<int> &nums, int k) {
    k = k % nums.size();
    const size_t size = nums.size() - k;
    std::vector<int> tmp(size);
    std::copy(nums.begin(), nums.begin() + size, tmp.begin());
    std::copy(nums.end() - k, nums.end(), nums.begin());
    std::copy(tmp.begin(), tmp.end(), nums.begin() + k);
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

    return 0;
}
