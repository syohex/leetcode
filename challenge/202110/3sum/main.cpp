#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    int len = nums.size();
    if (len < 3) {
        return ret;
    }

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < len - 2; ++i) {
        if (i > 0) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
        }

        int left = i + 1;
        int right = len - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                ret.push_back({nums[i], nums[left], nums[right]});

                int tmp = nums[left];
                ++left;
                while (left <= right && tmp == nums[left]) {
                    ++left;
                }

                tmp = nums[right];
                --right;
                while (left <= right && tmp == nums[right]) {
                    --right;
                }
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return ret;
}

void check(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
    assert(a.size() == b.size());

    std::vector<std::set<int>> av, bv;
    for (size_t i = 0; i < a.size(); ++i) {
        av.push_back(std::set<int>(a[i].begin(), a[i].end()));
        bv.push_back(std::set<int>(b[i].begin(), b[i].end()));
    }

    assert(av == bv);
}

int main() {
    {
        std::vector<int> nums{-1, 0, 1, 2, -1, 4};
        std::vector<std::vector<int>> expected{{-1, -1, 2}, {-1, 0, 1}};
        auto ret = threeSum(nums);
        check(ret, expected);
    }
    {
        std::vector<int> nums;
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
