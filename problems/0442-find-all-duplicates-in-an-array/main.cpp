#include <cassert>
#include <vector>
#include <cmath>

std::vector<int> findDuplicates(std::vector<int> &nums) {
    for (int num : nums) {
        nums[std::abs(num) - 1] *= -1;
    }

    std::vector<int> ret;
    for (int num : nums) {
        int index = std::abs(num) - 1;
        if (nums[index] > 0) {
            ret.push_back(std::abs(num));
            nums[index] *= -1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{4, 3, 2, 7, 8, 2, 3, 1};
        auto ret = findDuplicates(input);
        assert((ret == std::vector<int>{2, 3} || ret == std::vector<int>{3, 2}));
    }
    return 0;
}
