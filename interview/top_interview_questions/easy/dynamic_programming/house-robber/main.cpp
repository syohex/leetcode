#include <cassert>
#include <vector>
#include <algorithm>

int rob(const std::vector<int> &nums) {
    int prev = 0;
    int current = 0;

    for (const auto n : nums) {
        int tmp = current;
        current = std::max(prev + n, current);
        prev = tmp;
    }

    return current;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 1};
        assert(rob(nums) == 4);
    }
    {
        std::vector<int> nums{2, 7, 9, 3, 1};
        assert(rob(nums) == 12);
    }
    return 0;
}
