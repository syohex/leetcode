#include <cassert>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int> &nums) {
    int ret = nums[0];
    int sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (sum + nums[i] < nums[i]) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }

        ret = std::max(ret, sum);
    }

    return ret;
}

int main() {
    assert((maxSubArray(std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6));
    assert((maxSubArray(std::vector<int>{1}) == 1));
    assert((maxSubArray(std::vector<int>{0}) == 0));
    assert((maxSubArray(std::vector<int>{-1}) == -1));
    assert((maxSubArray(std::vector<int>{-2147483647}) == -2147483647));
}
