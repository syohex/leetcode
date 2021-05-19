#include <cassert>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>

int minMoves(const std::vector<int> &nums) {
    long ret = LONG_MAX;
    for (int n : nums) {
        long sum = 0;
        for (int m : nums) {
            sum += std::abs(n - m);
        }

        ret = std::min(ret, sum);
    }

    return static_cast<int>(ret);
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        assert(minMoves(nums) == 2);
    }
    {
        std::vector<int> nums{1, 10, 2, 9};
        assert(minMoves(nums) == 16);
    }
    return 0;
}
