#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

int findMaxLength(const std::vector<int> &nums) {
    std::map<int, int> m;
    m[0] = -1;

    int sum = 0;
    int ret = 0;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        sum += nums[i] == 0 ? -1 : 1;
        if (m.find(sum) != m.end()) {
            ret = std::max(ret, i - m[sum]);
        } else {
            m[sum] = i;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 1};
        int ret = findMaxLength(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{0, 1, 0};
        int ret = findMaxLength(nums);
        assert(ret == 2);
    }
    return 0;
}
