#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>

int beautifulSubsets(std::vector<int> &nums, int k) {
    std::function<int(std::size_t pos, std::map<int, int> & freq)> f;
    f = [&](std::size_t pos, std::map<int, int>& freq) -> int {
        if (pos >= nums.size()) {
            return freq.size() >= 1 ? 1 : 0;
        }

        int ret = f(pos + 1, freq);
        int diff = nums[pos] - k;
        if (freq[diff] == 0) {
            ++freq[nums[pos]];
            ret += f(pos + 1, freq);
            --freq[nums[pos]];
        }

        return ret;
    };

    std::sort(nums.begin(), nums.end());

    std::map<int, int> freq;
    return f(0, freq);
}

int main() {
    {
        std::vector<int> nums{2, 4, 6};
        int ret = beautifulSubsets(nums, 2);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{1};
        int ret = beautifulSubsets(nums, 1);
        assert(ret == 1);
    }
    return 0;
}
