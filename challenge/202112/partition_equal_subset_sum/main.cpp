#include <cassert>
#include <vector>
#include <functional>

bool canPartition(const std::vector<int> &nums) {
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }

    std::function<bool(size_t pos, int acc)> f;
    f = [&](size_t pos, int acc) -> bool {
        if (acc == sum - acc) {
            return true;
        }
        if (pos >= nums.size()) {
            return false;
        }

        return f(pos + 1, acc + nums[pos]) || f(pos + 1, acc);
    };

    return f(0, 0);
}

int main() {
    {
        std::vector<int> nums{1, 5, 11, 5};
        assert(canPartition(nums));
    }
    {
        std::vector<int> nums{1, 2, 3, 5};
        assert(!canPartition(nums));
    }
    return 0;
}
