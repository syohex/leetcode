#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int rob(const std::vector<int> &nums) {
    int max = 0;
    std::function<void(size_t pos, int sum, bool got, bool first)> f;
    f = [&f, &nums, &max](size_t pos, int sum, bool got, bool first) {
        if (pos >= nums.size()) {
            if (sum > max) {
                max = sum;
            }

            return;
        }

        if (!got && !(pos == nums.size() - 1 && first)) {
            if (pos == 0) {
                f(pos + 1, sum + nums[pos], true, true);
            } else {
                f(pos + 1, sum + nums[pos], true, first);
            }
        }

        f(pos + 1, sum, false, first);
    };

    f(0, 0, false, false);
    return max;
}

int main() {
    assert((rob(std::vector<int>{2, 3, 2}) == 3));
    assert(rob(std::vector<int>{1, 2, 3, 1}) == 4);
    assert(rob(std::vector<int>{0}) == 0);
    return 0;
}
