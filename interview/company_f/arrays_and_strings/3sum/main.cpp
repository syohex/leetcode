#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> ret;
    int limit = static_cast<int>(nums.size());
    for (int i = 0; i < limit - 2; ++i) {
        int start = i + 1;
        int end = nums.size() - 1;

        if (i >= 1 && nums[i - 1] == nums[i]) {
            continue;
        }

        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == 0) {
                ret.push_back(std::vector<int>{nums[i], nums[start], nums[end]});

                int tmp = nums[start];
                while (start < end && tmp == nums[start]) {
                    ++start;
                }
                tmp = nums[end];
                while (start < end && tmp == nums[end]) {
                    --end;
                }
            } else if (sum < 0) {
                ++start;
            } else {
                --end;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-1, 0, 1, 2, -1, -4};
        auto ret = threeSum(nums);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{-1, -1, 2}));
        assert((ret[1] == std::vector<int>{-1, 0, 1}));
    }
    {
        std::vector<int> nums{};
        auto ret = threeSum(nums);
        assert(ret.empty());
    }
    {
        std::vector<int> nums{0};
        auto ret = threeSum(nums);
        assert(ret.empty());
    }
    return 0;
}
