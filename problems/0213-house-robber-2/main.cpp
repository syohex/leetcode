#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

int rob(const std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    std::function<int(const std::vector<int> &nums, int start, int end)> f;
    f = [&f](const std::vector<int> &nums, int start, int end) -> int {
        int prev = 0;
        int curr = 0;

        for (int i = start; i <= end; ++i) {
            int tmp = curr;
            curr = std::max(prev + nums[i], curr);
            prev = tmp;
        }

        return curr;
    };

    int v1 = f(nums, 0, static_cast<int>(nums.size() - 2));
    int v2 = f(nums, 1, static_cast<int>(nums.size() - 1));

    return std::max(v1, v2);
}

int main() {
    assert((rob(std::vector<int>{2, 3, 2}) == 3));
    assert((rob(std::vector<int>{1, 2, 3, 1}) == 4));
    assert((rob(std::vector<int>{0}) == 0));
    assert((rob(std::vector<int>{1}) == 1));
    return 0;
}
