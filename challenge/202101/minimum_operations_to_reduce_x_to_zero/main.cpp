#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

int minOperations(const std::vector<int> &nums, int x) {
    std::vector<int> acc_left(nums.size() + 1, 0);
    std::map<int, int> m{
        {0, 0},
    };

    int sum = 0;
    for (size_t i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
        acc_left[i + 1] = acc_left[i] + nums[i];
        sum += nums[j];
        m[sum] = i + 1;
    }

    size_t ret = SIZE_MAX;
    for (size_t i = 0; i < acc_left.size(); ++i) {
        if (acc_left[i] > x) {
            break;
        }

        int diff = x - acc_left[i];
        auto it = m.find(diff);
        if (it == m.end()) {
            continue;
        }

        size_t tmp = i + it->second;
        if (tmp > nums.size()) {
            continue;
        }

        ret = std::min(ret, tmp);
    }

    return ret == SIZE_MAX ? -1 : static_cast<int>(ret);
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
