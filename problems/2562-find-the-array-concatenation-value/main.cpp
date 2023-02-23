#include <cassert>
#include <vector>
#include <string>

long long findTheArrayConcVal(const std::vector<int> &nums) {
    long long ret = 0;
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        ret += std::stoll(std::to_string(nums[left]) + std::to_string(nums[right]));
        ++left;
        --right;
    }

    if (nums.size() % 2 == 1) {
        ret += nums[left];
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{7, 52, 2, 4};
        auto ret = findTheArrayConcVal(nums);
        assert(ret == 596);
    }
    {
        std::vector<int> nums{5, 14, 13, 8, 12};
        auto ret = findTheArrayConcVal(nums);
        assert(ret == 673);
    }
    return 0;
}
