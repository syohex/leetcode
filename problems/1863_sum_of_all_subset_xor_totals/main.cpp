#include <cassert>
#include <vector>
#include <functional>

int subsetXORSum(const std::vector<int> &nums) {
    int ret = 0;
    std::function<void(size_t pos, int count, int acc)> f;
    f = [&f, &ret, &nums](size_t pos, int count, int acc) {
        if (pos >= nums.size()) {
            if (count == 0) {
                ret += acc;
            }
            return;
        }

        if (count >= 1) {
            f(pos + 1, count - 1, acc ^ nums[pos]);
        }

        f(pos + 1, count, acc);
    };

    int lens = nums.size();
    for (int i = 1; i <= lens; ++i) {
        f(0, i, 0);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3};
        assert(subsetXORSum(nums) == 6);
    }
    {
        std::vector<int> nums{5, 1, 6};
        assert(subsetXORSum(nums) == 28);
    }
    {
        std::vector<int> nums{3, 4, 5, 6, 7, 8};
        assert(subsetXORSum(nums) == 480);
    }
    return 0;
}
