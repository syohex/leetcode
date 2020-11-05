#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>

int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());

    int min = INT_MAX;
    int limit = static_cast<int>(nums.size());
    for (int i = 0; i < limit - 2; ++i) {
        int low = i + 1;
        int high = limit - 1;

        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];
            if (std::abs(target - sum) < std::abs(min)) {
                min = target - sum;
                if (min == 0) {
                    return target;
                }
            }

            if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
    }

    return target - min;
}

int main() {
    {
        std::vector<int> nums{-1, 2, 1, -4};
        assert(threeSumClosest(nums, 1) == 2);
    }
    {
        std::vector<int> nums{1, 1, -1, -1, 3};
        assert(threeSumClosest(nums, -1) == -1);
    }
    return 0;
}
