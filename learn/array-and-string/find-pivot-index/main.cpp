#include <cassert>
#include <vector>

int pivotIndex(const std::vector<int> &nums) {
    if (nums.size() <= 1) {
        return -1;
    }

    std::vector<int> v(nums.size());
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        v[i] = sum;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        int left_sum = i == 0 ? 0 : v[i - 1];
        int right_sum = v.back() - v[i];
        if (left_sum == right_sum) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> nums{1, 7, 3, 6, 5, 6};
        assert(pivotIndex(nums) == 3);
    }
    {
        std::vector<int> nums{1, 2, 3};
        assert(pivotIndex(nums) == -1);
    }
    {
        std::vector<int> nums{-1, -1, -1, 0, 1, 1};
        assert(pivotIndex(nums) == 0);
    }
    {
        std::vector<int> nums{-1, -1, 0, 1, 1, 99};
        assert(pivotIndex(nums) == 5);
    }
    {
        std::vector<int> nums{0, 0};
        assert(pivotIndex(nums) == 0);
    }
    {
        assert(pivotIndex(std::vector<int>{}) == -1);
        assert(pivotIndex(std::vector<int>{
                   1,
               }) == -1);
        assert(pivotIndex(std::vector<int>{1}) == -1);
    }
    return 0;
}
