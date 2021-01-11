#include <cassert>
#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int end = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] <= nums2[j]) {
            nums1[end] = nums2[j];
            --j;
        } else {
            nums1[end] = nums1[i];
            --i;
        }

        --end;
    }

    if (j >= 0) {
        while (j >= 0) {
            nums1[end--] = nums2[j--];
        }
    }
}

int main() {
    {
        std::vector<int> nums1{1, 2, 3, 0, 0, 0};
        std::vector<int> nums2{2, 5, 6};
        std::vector<int> expected{1, 2, 2, 3, 5, 6};
        merge(nums1, 3, nums2, 3);
        assert(nums1 == expected);
    }
    {
        std::vector<int> nums1{2, 5, 6, 0, 0, 0};
        std::vector<int> nums2{1, 2, 3};
        std::vector<int> expected{1, 2, 2, 3, 5, 6};
        merge(nums1, 3, nums2, 3);
        assert(nums1 == expected);
    }
    {
        std::vector<int> nums1{1};
        std::vector<int> nums2{};
        std::vector<int> expected{1};
        merge(nums1, 1, nums2, 0);
        assert(nums1 == expected);
    }
    return 0;
}
