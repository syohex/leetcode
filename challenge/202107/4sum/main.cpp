#include <cassert>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::set<std::vector<int>> s;
    int len = nums.size();
    for (int i = 0; i < len - 3; ++i) {
        for (int j = i + 1; j < len - 2; ++j) {
            int left = j + 1;
            int right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[left], nums[right]});
                    int tmp = nums[left];
                    ++left;
                    while (left < len && tmp == nums[left]) {
                        ++left;
                    }

                    tmp = nums[right];
                    --right;
                    while (right > left && tmp == nums[right]) {
                        --right;
                    }
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }

    return std::vector<std::vector<int>>(s.begin(), s.end());
}

void check(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
    assert(a.size() == b.size());

    std::set<std::vector<int>> as(a.begin(), a.end());
    std::set<std::vector<int>> bs(b.begin(), b.end());
    assert(as == bs);
}

int main() {
    {
        std::vector<int> nums{1, 0, -1, 0, -2, 2};
        std::vector<std::vector<int>> expected{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
        auto ret = fourSum(nums, 0);
        check(ret, expected);
    }
    {
        std::vector<int> nums{2, 2, 2, 2, 2};
        std::vector<std::vector<int>> expected{{2, 2, 2, 2}};
        auto ret = fourSum(nums, 8);
        check(ret, expected);
    }
    return 0;
}
