#include <cassert>
#include <vector>
#include <cstddef>
#include <functional>

int subsetXORSum(const std::vector<int> &nums) {
    std::function<int(size_t pos, int acc)> f;
    f = [&](size_t pos, int acc) -> int {
        if (pos >= nums.size()) {
            return acc;
        }

        int use_case = f(pos + 1, acc ^ nums[pos]);
        int unuse_case = f(pos + 1, acc);

        return use_case + unuse_case;
    };

    return f(0, 0);
}

int main() {
    {
        std::vector<int> nums{1, 3};
        int ret = subsetXORSum(nums);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{5, 1, 6};
        int ret = subsetXORSum(nums);
        assert(ret == 28);
    }
    {
        std::vector<int> nums{3, 4, 5, 6, 7, 8};
        int ret = subsetXORSum(nums);
        assert(ret == 480);
    }
    return 0;
}
