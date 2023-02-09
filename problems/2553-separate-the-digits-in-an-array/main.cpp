#include <cassert>
#include <vector>
#include <string>

std::vector<int> separateDigits(const std::vector<int> &nums) {
    std::vector<int> ret;
    for (int num : nums) {
        for (char c : std::to_string(num)) {
            ret.push_back(c - '0');
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{13, 25, 83, 77};
        std::vector<int> expected{1, 3, 2, 5, 8, 3, 7, 7};
        auto ret = separateDigits(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{7, 1, 3, 9};
        std::vector<int> expected{7, 1, 3, 9};
        auto ret = separateDigits(nums);
        assert(ret == expected);
    }
    return 0;
}
