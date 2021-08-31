#include <cassert>
#include <vector>

int findMin(const std::vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }

    if (nums[0] < nums.back()) {
        return nums[0];
    }

    int len = nums.size();
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid + 1 < len && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }

        if (nums[mid] > nums[0]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // never reach here
    return -1;
}

int main() {
    {
        std::vector<int> nums{3, 4, 5, 1, 2};
        assert(findMin(nums) == 1);
    }
    {
        std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
        assert(findMin(nums) == 0);
    }
    {
        std::vector<int> nums{11, 13, 15, 17};
        assert(findMin(nums) == 11);
    }
    return 0;
}