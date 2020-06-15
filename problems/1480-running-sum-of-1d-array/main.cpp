#include <cassert>
#include <vector>

std::vector<int> runningSum(const std::vector<int> &nums) {
    std::vector<int> ret;
    ret.resize(nums.size());
    ret[0] = nums[0];
    for (size_t i = 1; i < ret.size(); ++i) {
        ret[i] = ret[i - 1] + nums[i];
    }

    return ret;
}

int main() {
    assert((runningSum(std::vector<int>{1, 2, 3, 4}) == std::vector<int>{1, 3, 6, 10}));
    assert((runningSum(std::vector<int>{1, 1, 1, 1, 1}) == std::vector<int>{1, 2, 3, 4, 5}));
    assert((runningSum(std::vector<int>{3, 1, 2, 10, 1}) == std::vector<int>{3, 4, 6, 16, 17}));
    return 0;
}
