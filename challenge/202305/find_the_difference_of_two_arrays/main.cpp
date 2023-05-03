#include <cassert>
#include <vector>
#include <set>

std::vector<std::vector<int>> findDifference(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::vector<std::vector<int>> ret(2, std::vector<int>{});

    std::set<int> s1(nums1.begin(), nums1.end());
    std::set<int> s2(nums2.begin(), nums2.end());

    for (int i : s1) {
        if (s2.find(i) == s2.end()) {
            ret[0].push_back(i);
        }
    }
    for (int i : s2) {
        if (s1.find(i) == s1.end()) {
            ret[1].push_back(i);
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums1{1, 2, 3};
        std::vector<int> nums2{2, 4, 6};
        std::vector<std::vector<int>> expected{{1, 3}, {4, 6}};
        auto ret = findDifference(nums1, nums2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums1{1, 2, 3, 3};
        std::vector<int> nums2{1, 1, 2, 2};
        std::vector<std::vector<int>> expected{{3}, {}};
        auto ret = findDifference(nums1, nums2);
        assert(ret == expected);
    }
    return 0;
}
