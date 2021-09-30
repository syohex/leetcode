#include <cassert>
#include <vector>
#include <functional>

bool canPartitionLSubsets(const std::vector<int> &nums, int k) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    if (sum % k != 0) {
        return false;
    }

    int val = sum / k;
    int len = nums.size();

    std::function<bool(int sum, int count, std::vector<bool> &checked)> f;
    f = [&](int sum, int count, std::vector<bool> &checked) -> bool {
        if (count == k) {
            return true;
        }

        if (sum == val) {
            return f(0, count + 1, checked);
        }

        for (int i = 0; i < len; ++i) {
            if (!checked[i]) {
                checked[i] = true;

                if (sum + nums[i] <= val) {
                    if (f(sum + nums[i], count, checked)) {
                        return true;
                    }
                }

                checked[i] = false;
            }
        }

        return false;
    };

    std::vector<bool> checked(len, false);
    return f(0, 1, checked);
}

int main() {
    {
        std::vector<int> nums{4, 3, 2, 3, 5, 2, 1};
        assert(canPartitionLSubsets(nums, 4));
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        assert(!canPartitionLSubsets(nums, 3));
    }
    return 0;
}