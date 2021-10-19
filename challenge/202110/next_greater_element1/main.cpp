#include <cassert>
#include <vector>
#include <map>

std::vector<int> nextGreaterElement(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::map<int, int> m;
    int len = nums2.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums2[i] < nums2[j]) {
                m[nums2[i]] = nums2[j];
                break;
            }
        }
    }

    std::vector<int> ret;
    for (int num : nums1) {
        if (m.find(num) != m.end()) {
            ret.push_back(m[num]);
        } else {
            ret.push_back(-1);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums1{4, 1, 2};
        std::vector<int> nums2{1, 3, 4, 2};
        std::vector<int> expected{-1, 3, -1};
        auto ret = nextGreaterElement(nums1, nums2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums1{2, 4};
        std::vector<int> nums2{1, 2, 3, 4};
        std::vector<int> expected{3, -1};
        auto ret = nextGreaterElement(nums1, nums2);
        assert(ret == expected);
    }
    return 0;
}