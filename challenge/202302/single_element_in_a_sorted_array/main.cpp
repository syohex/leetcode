#include <cassert>
#include <vector>

int singleNonDuplicate(const std::vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid % 2 == 1) {
            mid -= 1;
        }

        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    {
        std::vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
        int ret = singleNonDuplicate(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{3, 3, 7, 7, 10, 11, 11};
        int ret = singleNonDuplicate(nums);
        assert(ret == 10);
    }
    return 0;
}
