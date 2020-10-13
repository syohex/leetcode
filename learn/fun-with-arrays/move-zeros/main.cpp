#include <cassert>
#include <vector>

void moveZeros(std::vector<int> &nums) {
    int non_zeros = 0;
    for (const int n : nums) {
        if (n == 0) {
            continue;
        }

        nums[non_zeros++] = n;
    }

    for (size_t i = non_zeros; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    {
        std::vector<int> input{0, 1, 0, 3, 12};
        moveZeros(input);
        assert((input == std::vector<int>{1, 3, 12, 0, 0}));
    }
    return 0;
}
