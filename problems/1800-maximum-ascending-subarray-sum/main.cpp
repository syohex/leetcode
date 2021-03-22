#include <cassert>
#include <vector>
#include <algorithm>

int maxAscendingSum(const std::vector<int> &nums) {
    int ret = nums[0];
    int sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i - 1]) {
            ret = std::max(ret, sum);
            sum = nums[i];
        } else {
            sum += nums[i];
        }
    }

    return std::max(ret, sum);
}

int main() {
    assert((maxAscendingSum(std::vector<int>{10, 20, 30, 5, 10, 50}) == 65));
    assert((maxAscendingSum(std::vector<int>{10, 20, 30, 40, 50}) == 150));
    assert((maxAscendingSum(std::vector<int>{12, 17, 15, 13, 10, 11, 12}) == 33));
    assert((maxAscendingSum(std::vector<int>{1, 1, 1, 1, 1}) == 1));
    return 0;
}
