#include <cassert>
#include <vector>
#include <functional>

int rob(const std::vector<int> &nums) {
    int max = 0;
    std::function<void(size_t index, int sum, bool skip)> f;
    f = [&f, &max, &nums](size_t index, int sum, bool skip) {
        if (index >= nums.size()) {
            if (sum > max) {
                max = sum;
            }
            return;
        }

        if (!skip) {
            f(index + 1, sum + nums[index], true);
        }
        f(index + 1, sum, false);
    };

    f(0, 0, false);
    return max;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 1};
        assert(rob(input) == 4);
    }
    {
        std::vector<int> input{2, 7, 9, 3, 1};
        assert(rob(input) == 12);
    }
    return 0;
}
