#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

int minOperations(const std::vector<int> &nums, int x) {
    int limit = nums.size();
    std::vector<int> acc;
    std::map<int, int> m{
        {0, 0},
    };

    acc.push_back(0);
    for (int num : nums) {
        int val = acc.back() + num;
        if (val > x) {
            break;
        }

        acc.push_back(val);
    }

    int sum = 0;
    for (int i = 0, j = limit - 1; i < limit; ++i, --j) {
        sum += nums[j];
        if (sum > x) {
            break;
        }

        m[sum] = i + 1;
    }

    int ret = INT_MAX;
    for (int i = 0; i < static_cast<int>(acc.size()); ++i) {
        int diff = x - acc[i];
        auto it = m.find(diff);
        if (it == m.end()) {
            continue;
        }

        int tmp = i + it->second;
        if (tmp > limit) {
            continue;
        }

        ret = std::min(ret, tmp);
    }

    return ret == INT_MAX ? -1 : static_cast<int>(ret);
}

int main() {
    {
        std::vector<int> nums{1, 1, 4, 2, 3};
        assert(minOperations(nums, 5) == 2);
    }
    {
        std::vector<int> nums{5, 6, 7, 8, 9};
        assert(minOperations(nums, 4) == -1);
    }
    {
        std::vector<int> nums{3, 2, 20, 1, 1, 3};
        assert(minOperations(nums, 10) == 5);
    }
    {
        std::vector<int> nums{1, 1};
        assert(minOperations(nums, 3) == -1);
    }
    return 0;
}
