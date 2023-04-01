#include <cassert>
#include <vector>

int search(const std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> nums{-1, 0, 3, 5, 9, 12};
        int ret = search(nums, 9);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{-1, 0, 3, 5, 9, 12};
        int ret = search(nums, 2);
        assert(ret == -1);
    }
    {
        std::vector<int> nums{1};
        int ret = search(nums, 1);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{-1};
        int ret = search(nums, 1);
        assert(ret == -1);
    }
    return 0;
}
