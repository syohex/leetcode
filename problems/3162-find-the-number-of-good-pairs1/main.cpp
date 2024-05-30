#include <cassert>
#include <vector>

int numberOfPairs(const std::vector<int> &nums1, const std::vector<int> &nums2, int k) {
    int ret = 0;
    for (int n : nums1) {
        for (int m : nums2) {
            if (n % (m * k) == 0) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums1{1, 3, 4};
        std::vector<int> nums2{1, 3, 4};
        int ret = numberOfPairs(nums1, nums2, 1);
        assert(ret == 5);
    }
    {
        std::vector<int> nums1{1, 2, 4, 12};
        std::vector<int> nums2{2, 4};
        int ret = numberOfPairs(nums1, nums2, 3);
        assert(ret == 2);
    }
    return 0;
}
