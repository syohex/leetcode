#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int longestSubsequence(const std::vector<int> &arr, int difference) {
    int ret = 1;
    int len = arr.size();
    std::vector<int> dp(len, 1);

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] - arr[j] == difference) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                ret = std::max(ret, dp[i]);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> arr{1, 2, 3, 4};
        int ret = longestSubsequence(arr, 1);
        assert(ret == 4);
    }
    {
        std::vector<int> arr{1, 3, 5, 7};
        int ret = longestSubsequence(arr, 1);
        assert(ret == 1);
    }
    {
        std::vector<int> arr{1, 5, 7, 8, 5, 3, 4, 2, 1};
        int ret = longestSubsequence(arr, -2);
        assert(ret == 4);
    }
    return 0;
}
