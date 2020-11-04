#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    if (nums.size() < 3) {
        return ret;
    }

    std::sort(nums.begin(), nums.end());

    int limit = static_cast<int>(nums.size());
    for (int i = 0; i < limit; ++i) {
        if (nums[i] > 0) {
            continue;
        }

        if (i != 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        int low = i + 1;
        int high = limit - 1;

        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum < 0) {
                ++low;
            } else if (sum > 0) {
                --high;
            } else {
                ret.emplace_back(std::vector<int>{nums[i], nums[low], nums[high]});
                ++low;
                --high;

                while (low < high && nums[low - 1] == nums[low]) {
                    ++low;
                }
                while (low < high && nums[high] == nums[high + 1]) {
                    --high;
                }
            }
        }
    }

    return ret;
}

bool check(const std::vector<std::vector<int>> &got, const std::vector<std::vector<int>> &expected) {
    if (got.size() != expected.size()) {
        return 0;
    }

    std::set<std::vector<int>> g, e;
    for (size_t i = 0; i < got.size(); ++i) {
        g.insert(got[i]);
        e.insert(expected[i]);
    }

    return g == e;
}

int main() {
    {
        std::vector<int> input{-1, 0, 1, 2, -1, 4};
        std::vector<std::vector<int>> expected{
            {-1, 0, 1},
            {-1, -1, 2},
        };
        auto ret = threeSum(input);
        assert(check(ret, expected));
    }
    {
        std::vector<int> input{3, 0, -2, -1, 1, 2};
        std::vector<std::vector<int>> expected{
            {-2, -1, 3},
            {-2, 0, 2},
            {-1, 0, 1},
        };
        auto ret = threeSum(input);
        assert(check(ret, expected));
    }
    return 0;
}
