#include <cassert>
#include <vector>

void sortColors(std::vector<int> &nums) {
    std::vector<int> counts(3, 0);
    for (int num : nums) {
        ++counts[num];
    }

    int p = 0;
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            nums[p++] = i;
        }
    }
}

int main() {
    {
        std::vector<int> nums{2, 0, 2, 1, 1, 0};
        std::vector<int> expected{0, 0, 1, 1, 2, 2};
        sortColors(nums);
        assert(nums == expected);
    }
    {
        std::vector<int> nums{2, 0, 1};
        std::vector<int> expected{0, 1, 2};
        sortColors(nums);
        assert(nums == expected);
    }
    {
        std::vector<int> nums{0};
        std::vector<int> expected{0};
        sortColors(nums);
        assert(nums == expected);
    }
    {
        std::vector<int> nums{1};
        std::vector<int> expected{1};
        sortColors(nums);
        assert(nums == expected);
    }
    return 0;
}
