#include <cassert>
#include <vector>
#include <algorithm>

int addedInteger(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    int min1 = *std::min_element(nums1.begin(), nums1.end());
    int min2 = *std::min_element(nums2.begin(), nums2.end());
    return min2 - min1;
}

int main() {
    {
        std::vector<int> nums1{2, 6, 4};
        std::vector<int> nums2{9, 7, 5};
        int ret = addedInteger(nums1, nums2);
        assert(ret == 3);
    }
    {
        std::vector<int> nums1{10};
        std::vector<int> nums2{5};
        int ret = addedInteger(nums1, nums2);
        assert(ret == -5);
    }
    {
        std::vector<int> nums1{1, 1, 1, 1};
        std::vector<int> nums2{1, 1, 1, 1};
        int ret = addedInteger(nums1, nums2);
        assert(ret == 0);
    }
    return 0;
}
