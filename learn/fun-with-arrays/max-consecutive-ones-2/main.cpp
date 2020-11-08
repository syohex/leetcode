#include <cassert>
#include <vector>
#include <cstdio>
#include <algorithm>

int findMaxConsecutiveOnes(const std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    struct Info {
        int val = 0;
        int count = 0;
    };

    std::vector<Info> v;
    int prev = nums[0];
    int count = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (prev == nums[i]) {
            ++count;
        } else {
            v.emplace_back(Info{prev, count});
            prev = nums[i];
            count = 1;
        }
    }

    v.emplace_back(Info{prev, count});

    int max = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        const auto &info = v[i];
        if (info.val == 0) {
            if (i + 1 < v.size()) {
                max = std::max(max, 1 + v[i + 1].count);
            } else {
                max = std::max(max, 1);
            }
        } else {
            if (i + 1 < v.size()) {
                const auto &next = v[i + 1];
                if (next.val == 0 && next.count == 1) {
                    if (i + 2 < v.size()) {
                        const auto &next_one = v[i + 2];
                        max = std::max(max, info.count + 1 + next_one.count);
                    } else {
                        max = std::max(max, info.count + 1);
                    }
                } else {
                    max = std::max(max, info.count);
                }
            } else {
                max = std::max(max, info.count);
            }
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> nums{1, 0, 1, 1, 0};
        assert(findMaxConsecutiveOnes(nums) == 4);
    }
    {
        std::vector<int> nums{0, 1};
        assert(findMaxConsecutiveOnes(nums) == 2);
    }
    return 0;
}
