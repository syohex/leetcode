#include <cassert>
#include <vector>
#include <algorithm>

int arrayNesting(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<bool> checked(len, false);

    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (!checked[i]) {
            int count = 0;
            int pos = nums[i];

            do {
                pos = nums[pos];
                ++count;
                checked[pos] = true;
            } while (pos != nums[i]);

            ret = std::max(ret, count);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{5, 4, 0, 3, 1, 6, 2};
        assert(arrayNesting(nums) == 4);
    }
    {
        std::vector<int> nums{0, 1, 2};
        assert(arrayNesting(nums) == 1);
    }
    return 0;
}