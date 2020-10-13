#include <cassert>
#include <vector>
#include <cstdio>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    int uniques = 1;
    int val = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (val == nums[i]) {
            continue;
        }

        nums[uniques++] = nums[i];
        val = nums[i];
    }

    return uniques;
}

int main() {
    {
        std::vector<int> inputs{1, 1, 2};
        auto ret = removeDuplicates(inputs);
        assert(ret == 2);
        inputs.resize(ret);
        assert((inputs == std::vector<int>{1, 2}));
    }
    {
        std::vector<int> inputs{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        auto ret = removeDuplicates(inputs);
        assert(ret == 5);
        inputs.resize(ret);
        assert((inputs == std::vector<int>{0, 1, 2, 3, 4}));
    }
    return 0;
}
