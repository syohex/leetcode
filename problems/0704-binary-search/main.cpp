#include <cassert>
#include <vector>
#include <cstdio>

int search(const std::vector<int> &nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    if (nums.size() == 1) {
        return (nums[0] == target) ? 0 : -1;
    }

    size_t left = 0;
    size_t right = nums.size() - 1;
    if (nums[left] > target || nums[right] < target) {
        return -1;
    }

    while (left <= right) {
        size_t mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    assert((search(std::vector<int>{}, 9) == -1));
    assert((search(std::vector<int>{5}, 5) == 0));
    assert((search(std::vector<int>{5}, -5) == -1));
    assert((search(std::vector<int>{2, 5}, 5) == 1));
    assert((search(std::vector<int>{1, 2}, 0) == -1));
    assert((search(std::vector<int>{-1, 0, 3, 5, 9, 12}, 9) == 4));
    assert((search(std::vector<int>{-1, 0, 3, 5, 9, 12}, 2) == -1));
    return 0;
}
