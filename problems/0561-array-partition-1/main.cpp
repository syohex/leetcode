#include <cassert>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int sum = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    {
        std::vector<int> input{1, 4, 3, 2};
        assert(arrayPairSum(input) == 4);
    }
    return 0;
}
