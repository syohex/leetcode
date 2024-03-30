#include <cassert>
#include <algorithm>

long long countSubarrays(const std::vector<int> &nums, int k) {
    int max_val = *std::max_element(nums.begin(), nums.end());

    long long ret = 0;
    size_t left = 0;
    size_t right = 0;

    int count = 0;
    while (right < nums.size()) {
        if (nums[right] == max_val) {
            ++count;
        }

        while (left < nums.size() && count >= k) {
            if (nums[left] == max_val) {
                --count;
            }

            ++left;
        }

        ret += left;
        ++right;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 2, 3, 3};
        auto ret = countSubarrays(nums, 2);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{1, 4, 2, 1};
        auto ret = countSubarrays(nums, 3);
        assert(ret == 0);
    }
    return 0;
}
