#include <cassert>
#include <vector>
#include <functional>
#include <map>

bool canPartition(const std::vector<int> &nums) {
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }

    if (sum % 2 != 0) {
        return false;
    }

    int subset_sum = sum / 2;
    std::map<size_t, std::map<int, bool>> cache;
    std::function<bool(int pos, int acc)> f;
    f = [&](int pos, int acc) -> bool {
        if (acc == 0) {
            return true;
        }
        if (pos < 0 || acc < 0) {
            return false;
        }

        if (cache[pos].find(acc) != cache[pos].end()) {
            return cache[pos][acc];
        }

        bool ret = f(pos - 1, acc - nums[pos]) || f(pos - 1, acc);
        cache[pos][acc] = ret;
        return ret;
    };

    int len = nums.size();
    return f(len - 1, subset_sum);
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
