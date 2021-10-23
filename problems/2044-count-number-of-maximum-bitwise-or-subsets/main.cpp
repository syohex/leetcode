#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

int countMaxOrSubsets(const std::vector<int> &nums) {
    std::map<int, int> m;
    int max = 0;
    std::function<void(size_t pos, int acc)> f;
    f = [&](size_t pos, int acc) {
        if (pos == nums.size()) {
            return;
        }

        int val = acc | nums[pos];
        max = std::max(max, val);
        ++m[val];
        f(pos + 1, val);
        f(pos + 1, acc);
    };

    f(0, 0);
    return m[max];
}

int main() {
    {
        std::vector<int> nums{3, 1};
        assert(countMaxOrSubsets(nums) == 2);
    }
    {
        std::vector<int> nums{2, 2, 2};
        assert(countMaxOrSubsets(nums) == 7);
    }
    {
        std::vector<int> nums{3, 2, 1, 5};
        assert(countMaxOrSubsets(nums) == 6);
    }
    return 0;
}