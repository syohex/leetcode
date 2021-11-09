#include <cassert>
#include <vector>

int singleNumber(const std::vector<int> &nums) {
    int n = 0;
    for (int num : nums) {
        n ^= num;
    }

    return n;
}

int main() {
    {
        std::vector<int> nums{2, 2, 1};
        assert(singleNumber(nums) == 1);
    }
    {
        std::vector<int> nums{4, 1, 2, 1, 2};
        assert(singleNumber(nums) == 4);
    }
    {
        std::vector<int> nums{1};
        assert(singleNumber(nums) == 1);
    }

    return 0;
}
