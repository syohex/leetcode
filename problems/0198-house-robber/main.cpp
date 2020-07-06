#include <cassert>
#include <vector>
#include <functional>

int rob(const std::vector<int> &nums) {
    int max = 0;
    std::function<void(size_t index, int sum, bool canRob, int skips)> f;
    f = [&f, &max, &nums](size_t index, int sum, bool canRob, int skips) {
        if (index >= nums.size()) {
            if (sum > max) {
                max = sum;
            }
            return;
        }

        if (canRob) {
            f(index + 1, sum + nums[index], false, 0);
        }
        if (skips < 1) {
            if (canRob) {
                f(index + 1, sum, true, skips + 1);
            } else {
                f(index + 1, sum, true, skips);
            }
        }
    };

    f(0, 0, true, 0);
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
    {
        std::vector<int> input{2, 1, 1, 2};
        assert(rob(input) == 4);
    }
    return 0;
}
