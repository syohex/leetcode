#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

int sumCounts(const std::vector<int> &nums) {
    int len = nums.size();

    int ret = len;
    for (int i = 2; i <= len; ++i) {
        std::map<int, int> m;
        for (int j = 0; j < i; ++j) {
            ++m[nums[j]];
        }

        int count = m.size();
        ret += count * count;
        for (int j = i; j < len; ++j) {
            --m[nums[j - i]];
            if (m[nums[j - i]] == 0) {
                --count;
            }
            ++m[nums[j]];
            if (m[nums[j]] == 1) {
                ++count;
            }

            ret += count * count;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 1};
        int ret = sumCounts(nums);
        assert(ret == 15);
    }
    {
        std::vector<int> nums{1, 1};
        int ret = sumCounts(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{2, 2, 5, 5};
        int ret = sumCounts(nums);
        assert(ret == 22);
    }
    return 0;
}
