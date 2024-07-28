#include <cassert>
#include <vector>

bool canAliceWin(const std::vector<int> &nums) {
    int single_sum = 0;
    int double_sum = 0;

    for (int num : nums) {
        if (num < 10) {
            single_sum += num;
        } else {
            double_sum += num;
        }
    }

    return single_sum != double_sum;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4, 10};
        assert(!canAliceWin(nums));
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5, 14};
        assert(canAliceWin(nums));
    }
    {
        std::vector<int> nums{5, 5, 25};
        assert(canAliceWin(nums));
    }
    return 0;
}
