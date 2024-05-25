#include <cassert>
#include <vector>

bool isArraySpecial(const std::vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        bool a = nums[i] & 1;
        bool b = nums[i + 1] & 1;
        if (a == b) {
            return false;
        }
    }
    return true;
}

int main() {
    {
        std::vector<int> nums{1};
        assert(isArraySpecial(nums));
    }
    {
        std::vector<int> nums{2, 1, 4};
        assert(isArraySpecial(nums));
    }
    {
        std::vector<int> nums{4, 3, 1, 6};
        assert(!isArraySpecial(nums));
    }
    return 0;
}
