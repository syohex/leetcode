#include <cassert>
#include <cstddef>
#include <vector>
#include <set>

bool findSubarrays(const std::vector<int> &nums) {
    int sum = nums[0] + nums[1];
    std::set<int> s;
    s.insert(sum);

    size_t len = nums.size();
    for (size_t i = 2; i < len; ++i) {
        sum = sum - nums[i - 2] + nums[i];
        if (s.find(sum) != s.end()) {
            return true;
        }
        s.insert(sum);
    }

    return false;
}

int main() {
    {
        std::vector<int> nums{4, 2, 4};
        assert(findSubarrays(nums));
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        assert(!findSubarrays(nums));
    }
    {
        std::vector<int> nums{0, 0, 0};
        assert(findSubarrays(nums));
    }
    return 0;
}
