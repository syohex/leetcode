#include <cassert>
#include <vector>
#include <cstdio>

std::vector<std::vector<int>> mergeArrays(const std::vector<std::vector<int>> &nums1, const std::vector<std::vector<int>> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    std::vector<std::vector<int>> ret;
    for (int i = 0, j = 0; i < len1 || j < len2;) {
        if (i == len1) {
            ret.push_back({nums2[j][0], nums2[j][1]});
            ++j;
            continue;
        }
        if (j == len2) {
            ret.push_back({nums1[i][0], nums1[i][1]});
            ++i;
            continue;
        }

        if (nums1[i][0] == nums2[j][0]) {
            ret.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            ++i;
            ++j;
        } else if (nums1[i][0] < nums2[j][0]) {
            ret.push_back({nums1[i][0], nums1[i][1]});
            ++i;
        } else {
            ret.push_back({nums2[j][0], nums2[j][1]});
            ++j;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> nums1{{1, 2}, {2, 3}, {4, 5}};
        std::vector<std::vector<int>> nums2{{1, 4}, {3, 2}, {4, 1}};
        std::vector<std::vector<int>> expected{{1, 6}, {2, 3}, {3, 2}, {4, 6}};
        auto ret = mergeArrays(nums1, nums2);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> nums1{{2, 4}, {3, 6}, {5, 5}};
        std::vector<std::vector<int>> nums2{{1, 3}, {4, 3}};
        std::vector<std::vector<int>> expected{{1, 3}, {2, 4}, {3, 6}, {4, 3}, {5, 5}};
        auto ret = mergeArrays(nums1, nums2);
        assert(ret == expected);
    }
    return 0;
}
