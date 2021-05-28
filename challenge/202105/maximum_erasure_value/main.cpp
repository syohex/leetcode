#include <cassert>
#include <vector>
#include <algorithm>
#include <set>

int maximumUniqueSubarray(const std::vector<int> &nums) {
    int ret = 0;
    int lens = nums.size();
    for (int i = 0; i < lens; ++i) {
        std::set<int> s;
        s.insert(nums[i]);
        int sum = nums[i];
        for (int j = i + 1; j < lens; ++j) {
            if (s.find(nums[j]) != s.end()) {
                break;
            }

            sum += nums[j];
            s.insert(nums[j]);
        }

        ret = std::max(ret, sum);
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 2, 4, 5, 6};
        assert(maximumUniqueSubarray(nums) == 17);
    }
    {
        std::vector<int> nums{5, 2, 1, 2, 5, 2, 1, 2, 5};
        assert(maximumUniqueSubarray(nums) == 8);
    }
    return 0;
}
