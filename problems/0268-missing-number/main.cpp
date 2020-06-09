#include <cassert>
#include <vector>
#include <cstdio>

int missingNumber(const std::vector<int> &nums) {
    int n = nums.size();
    int v = n * (1 + n) / 2;
    int sum = 0;
    for (const auto i : nums) {
        sum += i;
    }

    return v - sum;
}

int main() {
    assert((missingNumber(std::vector<int>{3, 0, 1}) == 2));
    assert((missingNumber(std::vector<int>{9, 6, 4, 2, 3, 5, 7, 0, 1}) == 8));
    return 0;
}
