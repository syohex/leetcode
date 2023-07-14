#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

int longestSubsequence(const std::vector<int> &arr, int difference) {
    int ret = 1;
    std::map<int, int> m;

    for (int num : arr) {
        int prev_len = m[num - difference];
        m[num] = prev_len + 1;
        ret = std::max(ret, m[num]);
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
