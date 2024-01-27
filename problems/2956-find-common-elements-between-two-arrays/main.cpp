#include <cassert>
#include <vector>
#include <set>

std::vector<int> findIntersectionValues(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::set<int> s1(nums1.begin(), nums1.end());
    std::set<int> s2(nums2.begin(), nums2.end());

    int ret1 = 0;
    for (int num : nums1) {
        if (s2.find(num) != s2.end()) {
            ++ret1;
        }
    }

    int ret2 = 0;
    for (int num : nums2) {
        if (s1.find(num) != s1.end()) {
            ++ret2;
        }
    }
    return {ret1, ret2};
}

int main() {
    {
        std::vector<int> nums1{4, 3, 2, 3, 1};
        std::vector<int> nums2{2, 2, 5, 2, 3, 6};
        std::vector<int> expected{3, 4};
        auto ret = findIntersectionValues(nums1, nums2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums1{3, 4, 2, 3};
        std::vector<int> nums2{1, 5};
        std::vector<int> expected{0, 0};
        auto ret = findIntersectionValues(nums1, nums2);
        assert(ret == expected);
    }
    return 0;
}
