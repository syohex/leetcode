#include <cassert>
#include <vector>
#include <map>

int subarraySum(const std::vector<int> &nums, int k) {
    std::vector<int> sums(nums.size());
    sums[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        sums[i] = nums[i] + sums[i - 1];
    }

    std::map<int, int> m;
    int ret = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        int diff = sums[i] - k;
        if (m.find(diff) != m.end()) {
            ret += m[diff];
        }
        if (diff == 0) {
            ++ret;
        }

        ++m[sums[i]];
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 1, 1};
        assert(subarraySum(nums, 2) == 2);
    }
    {
        std::vector<int> nums{1, 2, 3};
        assert(subarraySum(nums, 3) == 2);
    }
    return 0;
}
