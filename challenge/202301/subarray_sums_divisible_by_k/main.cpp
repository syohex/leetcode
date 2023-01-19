#include <cassert>
#include <vector>
#include <map>

int subArraysDivByK(const std::vector<int> &nums, int k) {
    std::map<int, int> m;
    m[0] = 1;

    int ret = 0;
    int prefix_sum = 0;
    for (int num : nums) {
        prefix_sum = (prefix_sum + (num % k) + k) % k;
        ret += m[prefix_sum];
        m[prefix_sum] += 1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 5, 0, -2, -3, 1};
        int ret = subArraysDivByK(nums, 5);
        assert(ret == 7);
    }
    {
        std::vector<int> nums{5};
        int ret = subArraysDivByK(nums, 9);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{7, 4, -10};
        int ret = subArraysDivByK(nums, 5);
        assert(ret == 1);
    }
    return 0;
}
