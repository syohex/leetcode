#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    if (nums.size() <= 2) {
        return ret;
    }

    std::sort(nums.begin(), nums.end());

    int limit = static_cast<int>(nums.size());
    for (int i = 0; i < limit - 2;) {
        if (nums[i] > 0) {
            break;
        }

        int start = i + 1;
        int end = limit - 1;

        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == 0) {
                ret.emplace_back(std::vector<int>{nums[i], nums[start], nums[end]});

                int tmp = nums[start];
                while (start < limit && nums[start] == tmp) {
                    ++start;
                }

                tmp = nums[end];
                while (end >= 0 && nums[end] == tmp) {
                    --end;
                }
            } else if (sum < 0) {
                ++start;
            } else {
                --end;
            }
        }

        int tmp = nums[i];
        ++i;
        while (i < limit && nums[i] == tmp) {
            ++i;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-1, 0, 1, 2, -1, -4};
        std::vector<std::vector<int>> expected{
            {-1, -1, 2},
            {-1, 0, 1},
        };
        auto ret = threeSum(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{};
        std::vector<std::vector<int>> expected{};
        auto ret = threeSum(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{0};
        std::vector<std::vector<int>> expected{};
        auto ret = threeSum(nums);
        assert(ret == expected);
    }
    return 0;
}
