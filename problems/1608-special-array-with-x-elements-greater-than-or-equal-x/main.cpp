#include <cassert>
#include <vector>
#include <cstdio>
#include <algorithm>

int specialArray(const std::vector<int> &nums) {
    for (int i = 0; i <= static_cast<int>(nums.size()); ++i) {
        int num = std::count_if(nums.begin(), nums.end(), [&i](int a) { return a >= i; });
        if (i == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    assert((specialArray(std::vector<int>{3, 5}) == 2));
    assert((specialArray(std::vector<int>{0, 0}) == -1));
    assert((specialArray(std::vector<int>{0, 4, 3, 0, 4}) == 3));
    assert((specialArray(std::vector<int>{3, 6, 7, 7, 0}) == -1));
    return 0;
}
