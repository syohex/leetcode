#include <cassert>
#include <vector>
#include <functional>
#include <map>

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

    std::map<std::vector<bool>, bool> cache;
    std::function<bool(int sum, int count, std::vector<bool> &checked)> f;
    f = [&](int sum, int count, std::vector<bool> &checked) -> bool {
        if (count == k) {
            cache[checked] = true;
            return true;
        }

        if (cache.find(checked) != cache.end()) {
            return cache.at(checked);
        }

        if (sum == val) {
            bool ret = f(0, count + 1, checked);
            cache[checked] = ret;
            return ret;
        }

        for (int i = 0; i < len; ++i) {
            if (!checked[i]) {
                checked[i] = true;

                if (sum + nums[i] <= val) {
                    if (f(sum + nums[i], count, checked)) {
                        cache[checked] = true;
                        return true;
                    }
                }

                checked[i] = false;
            }
        }

        cache[checked] = false;
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