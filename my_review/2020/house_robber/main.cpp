#include <cassert>
#include <vector>
#include <algorithm>

int rob(const std::vector<int> &nums) {
    int prev = 0;
    int curr = 0;
    for (const int num : nums) {
        int tmp = curr;
        curr = std::max(prev + num, curr);
        prev = tmp;
    }
    return curr;
}

int main() {
    assert((rob(std::vector<int>{1, 2, 3, 1}) == 4));
    assert((rob(std::vector<int>{2, 7, 9, 3, 1}) == 12));
    assert((rob(std::vector<int>{}) == 0));
    assert((rob(std::vector<int>{10}) == 10));
    return 0;
}
