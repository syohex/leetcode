#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    int count = 1;
    int prev = nums[0];
    int duplicated = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (prev == nums[i]) {
            ++duplicated;
            if (duplicated >= 3) {
                continue;
            }
        } else {
            prev = nums[i];
            duplicated = 1;
        }

        nums[count] = nums[i];
        ++count;
    }
    return count;
}

int main() {
    {
        std::vector<int> nums{1, 1, 1, 2, 2, 3};
        auto ret = removeDuplicates(nums);
        assert(ret == 5);

        std::vector<int> expected{1, 1, 2, 2, 3};
        assert(std::equal(expected.begin(), expected.end(), nums.begin()));
    }
    {
        std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
        auto ret = removeDuplicates(nums);
        assert(ret == 7);

        std::vector<int> expected{0, 0, 1, 1, 2, 3, 3};
        assert(std::equal(expected.begin(), expected.end(), nums.begin()));
    }
    return 0;
}
