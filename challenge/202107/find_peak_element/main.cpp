#include <cassert>
#include <vector>

int findPeakElement(const std::vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 1};
        assert(findPeakElement(nums) == 2);
    }
    {
        std::vector<int> nums{1, 2, 1, 3, 5, 6, 4};
        auto ret = findPeakElement(nums);
        assert(ret == 1 || ret == 5);
    }
    return 0;
}
