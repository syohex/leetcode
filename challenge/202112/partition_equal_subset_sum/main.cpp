#include <cassert>
#include <vector>
#include <functional>
#include <map>

bool canPartition(const std::vector<int> &nums) {
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }

    std::map<size_t, std::map<int, bool>> cache;
    std::function<bool(size_t pos, int acc)> f;
    f = [&](size_t pos, int acc) -> bool {
        if (acc == sum - acc) {
            return true;
        }
        if (pos >= nums.size()) {
            return false;
        }
        if (cache[pos].find(acc) != cache[pos].end()) {
            return cache[pos][acc];
        }

        bool ret = f(pos + 1, acc + nums[pos]) || f(pos + 1, acc);
        cache[pos][acc] = ret;
        return ret;
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
