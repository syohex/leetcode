#include <cassert>
#include <vector>
#include <algorithm>

int findLength(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
    int ret = 0;
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            if (nums1[i] == nums2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                ret = std::max(ret, dp[i][j]);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums1{1, 2, 3, 2, 1};
        std::vector<int> nums2{3, 2, 1, 4, 7};
        assert(findLength(nums1, nums2) == 3);
    }
    {
        std::vector<int> nums1{0, 0, 0, 0, 0};
        std::vector<int> nums2{0, 0, 0, 0, 0};
        assert(findLength(nums1, nums2) == 5);
    }
    return 0;
}
