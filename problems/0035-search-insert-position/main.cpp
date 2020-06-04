#include <cassert>
#include <vector>

int searchInsert(const std::vector<int> &nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i) {
        if (target <= nums[i]) {
            return i;
        }
    }
    return nums.size();
}

int main() {
    assert(searchInsert(std::vector<int>{1, 3, 5, 6}, 5) == 2);
    assert(searchInsert(std::vector<int>{1, 3, 5, 6}, 2) == 1);
    assert(searchInsert(std::vector<int>{1, 3, 5, 6}, 7) == 4);
    assert(searchInsert(std::vector<int>{1, 3, 5, 6}, 0) == 0);
    return 0;
}