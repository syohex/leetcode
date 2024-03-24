#include <cassert>
#include <vector>

int findDuplicate(const std::vector<int> &nums) {
    int left = 1;
    int right = nums.size() - 1;
    int ret = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (int num : nums) {
            if (num <= mid) {
                ++count;
            }
        }

        if (count > mid) {
            right = mid - 1;
            ret = mid;
        } else {
            left = mid + 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 4, 2, 2};
        int ret = findDuplicate(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{3, 1, 3, 4, 2};
        int ret = findDuplicate(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{3, 3, 3, 3, 3};
        int ret = findDuplicate(nums);
        assert(ret == 3);
    }
    return 0;
}
