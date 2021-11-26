#include <cassert>
#include <vector>

int searchInsert(const std::vector<int> &nums, int target) {
    int len = nums.size();
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> nums{1, 3, 5, 6};
        assert(searchInsert(nums, 5) == 2);
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        assert(searchInsert(nums, 2) == 1);
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        assert(searchInsert(nums, 7) == 4);
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        assert(searchInsert(nums, 0) == 0);
    }
    {
        std::vector<int> nums{1};
        assert(searchInsert(nums, 0) == 0);
    }
    {
        std::vector<int> nums{1};
        assert(searchInsert(nums, 1) == 0);
    }
    {
        std::vector<int> nums{1, 3};
        assert(searchInsert(nums, 2) == 1);
    }
    return 0;
}