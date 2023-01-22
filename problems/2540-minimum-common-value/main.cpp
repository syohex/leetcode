#include <cassert>
#include <vector>
#include <set>

int getCommon(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    for (int n1 : nums1) {
        for (int n2 : nums2) {
            if (n2 > n1) {
                break;
            }

            if (n1 == n2) {
                return n1;
            }
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> nums1{1, 2, 3};
        std::vector<int> nums2{2, 4};
        int ret = getCommon(nums1, nums2);
        assert(ret == 2);
    }
    {
        std::vector<int> nums1{1, 2, 3, 6};
        std::vector<int> nums2{2, 3, 4, 5};
        int ret = getCommon(nums1, nums2);
        assert(ret == 2);
    }
    return 0;
}
