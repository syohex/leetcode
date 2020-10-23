#include <cassert>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>

bool find132pattern(const std::vector<int> &nums) {
    if (nums.size() < 3) {
        return false;
    }

    for (size_t i = 0; i < nums.size() - 2; ++i) {
        for (size_t j = i + 1; j < nums.size() - 1; ++j) {
            if (nums[i] >= nums[j]) {
                break;
            }

            for (size_t k = j + 1; k < nums.size(); ++k) {
                if (nums[i] < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool find132pattern2(const std::vector<int> &nums) {
    if (nums.size() < 3) {
        return false;
    }

    int min_i_val = nums[0];
    for (size_t j = 1; j < nums.size() - 1; ++j) {
        min_i_val = std::min(min_i_val, nums[j]);
        if (min_i_val >= nums[j]) {
            continue;
        }
        for (size_t k = j + 1; k < nums.size(); ++k) {
            if (min_i_val < nums[k] && nums[k] < nums[j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    assert(!find132pattern(std::vector<int>{1, 2, 3, 4}));
    assert(find132pattern(std::vector<int>{3, 1, 4, 2}));
    assert(find132pattern(std::vector<int>{-1, 3, 2, 0}));

    assert(!find132pattern2(std::vector<int>{1, 2, 3, 4}));
    assert(find132pattern2(std::vector<int>{3, 1, 4, 2}));
    assert(find132pattern2(std::vector<int>{-1, 3, 2, 0}));
    return 0;
}
