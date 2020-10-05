#include <cassert>
#include <vector>
#include <cstdio>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    size_t num = nums[0];
    size_t index = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (num != nums[i]) {
            num = nums[i];
            nums[index++] = num;
        }
    }

    return static_cast<int>(index);
}

int main() {
    {
        std::vector<int> inputs{1, 1, 2};
        assert(removeDuplicates(inputs) == 2);
    }
    {
        std::vector<int> inputs{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        assert(removeDuplicates(inputs) == 5);
    }
    {
        std::vector<int> inputs{};
        assert(removeDuplicates(inputs) == 0);
    }
    return 0;
}
