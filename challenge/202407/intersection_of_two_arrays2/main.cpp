#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    size_t i = 0;
    size_t j = 0;

    std::vector<int> ret;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            ret.push_back(nums1[i]);
            ++i;
            ++j;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums1{1, 2, 2, 1};
        std::vector<int> nums2{2, 2};
        std::vector<int> expected{2, 2};

        auto ret = intersect(nums1, nums2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums1{4, 9, 5};
        std::vector<int> nums2{9, 4, 9, 8, 4};
        std::vector<int> expected{4, 9};

        auto ret = intersect(nums1, nums2);
        assert(ret == expected);
    }
    return 0;
}
