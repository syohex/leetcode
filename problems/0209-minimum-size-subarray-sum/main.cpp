#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

int minSubArrayLen(int s, const std::vector<int> &nums) {
    std::vector<int> acc(nums.size() + 1, 0);
    acc[0] = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        acc[i + 1] = acc[i] + nums[i];
    }

    int ret = INT_MAX;
    for (size_t i = 1; i < acc.size(); ++i) {
        int val = s + acc[i - 1];
        for (size_t j = i; j < acc.size(); ++j) {
            if (val <= acc[j]) {
                int tmp = j - i + 1;
                ret = std::min(ret, tmp);
                break;
            }
        }
    }

    return ret == INT_MAX ? 0 : ret;
}

int main() {
    {
        std::vector<int> nums{2, 3, 1, 2, 4, 3};
        assert(minSubArrayLen(7, nums) == 2);
    }
    return 0;
}
