#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int threeSumSmaller(std::vector<int> &nums, int target) {
    if (nums.size() < 3) {
        return 0;
    }

    std::sort(nums.begin(), nums.end());

    int ret = 0;
    int limit = static_cast<int>(nums.size());
    for (int i = 0; i < limit - 2; ++i) {
        int low = i + 1;
        int high = limit - 1;

        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum < target) {
                ret += high - low;
                ++low;
            } else if (sum >= target) {
                --high;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-2, 0, 1, 3};
        assert(threeSumSmaller(nums, 2) == 2);
    }
    {
        std::vector<int> nums{};
        assert(threeSumSmaller(nums, 0) == 0);
    }
    {
        std::vector<int> nums{0};
        assert(threeSumSmaller(nums, 0) == 0);
    }
    return 0;
}
