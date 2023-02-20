#include <cassert>
#include <vector>

int searchInsert(const std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    {
        std::vector<int> nums{1, 3, 5, 6};
        int ret = searchInsert(nums, 5);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        int ret = searchInsert(nums, 2);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        int ret = searchInsert(nums, 7);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        int ret = searchInsert(nums, 7);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{1};
        int ret = searchInsert(nums, 1);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{1, 3};
        int ret = searchInsert(nums, 2);
        assert(ret == 1);
    }

    return 0;
}
