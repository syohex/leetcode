#include <cassert>
#include <vector>
#include <functional>

std::vector<int> sortArray(std::vector<int> &nums) {
    std::function<void(int left, int right, std::vector<int> &tmp)> merge;
    merge = [&](int left, int right, std::vector<int> &tmp) {
        int mid = (left + right) / 2;
        int right_start = mid + 1;

        int left_len = mid - left + 1;
        int right_len = right - mid;

        for (int i = 0; i < left_len; ++i) {
            tmp[left + i] = nums[left + i];
        }
        for (int i = 0; i < right_len; ++i) {
            tmp[right_start + i] = nums[right_start + i];
        }

        int i = 0;
        int j = 0;
        int k = left;
        while (i < left_len && j < right_len) {
            if (tmp[left + i] <= tmp[right_start + j]) {
                nums[k] = tmp[left + i];
                ++i;
            } else {
                nums[k] = tmp[right_start + j];
                ++j;
            }

            ++k;
        }

        while (i < left_len) {
            nums[k] = tmp[left + i];
            ++k;
            ++i;
        }
        while (j < right_len) {
            nums[k] = tmp[right_start + j];
            ++k;
            ++j;
        }
    };

    std::function<void(int left, int right, std::vector<int> &tmp)> merge_sort;
    merge_sort = [&](int left, int right, std::vector<int> &tmp) {
        if (left >= right) {
            return;
        }

        int mid = (left + right) / 2;
        merge_sort(left, mid, tmp);
        merge_sort(mid + 1, right, tmp);

        merge(left, right, tmp);
    };

    std::vector<int> tmp(nums.size(), 0);
    merge_sort(0, nums.size() - 1, tmp);
    return nums;
}

int main() {
    {
        std::vector<int> nums{5, 2, 3, 1};
        std::vector<int> expected{1, 2, 3, 5};
        auto ret = sortArray(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{5, 1, 1, 2, 0, 0};
        std::vector<int> expected{0, 0, 1, 1, 2, 5};
        auto ret = sortArray(nums);
        assert(ret == expected);
    }
    return 0;
}