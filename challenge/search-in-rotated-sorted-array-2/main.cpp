#include <cassert>
#include <vector>

int pivot_index(const std::vector<int> &nums) {
    int last_index = static_cast<int>(nums.size() - 1);
    int left = 0;
    int right = last_index;
    if (nums[left] < nums[right]) {
        return left;
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        int next_index = mid == last_index ? 0 : mid + 1;
        if (nums[mid] > nums[next_index]) {
            return next_index;
        }

        if (nums[left] > nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}

bool binary_search(const std::vector<int> &nums, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }

        if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}

bool search(const std::vector<int> &nums, int target) {
    if (nums.empty()) {
        return false;
    }

    if (nums.size() == 1) {
        return nums[0] == target;
    }

    int index = pivot_index(nums);
    if (nums[index] > target) {
        return false;
    }

    int last_index = static_cast<int>(nums.size() - 1);
    if (index == 0) {
        return binary_search(nums, 0, last_index, target);
    }

    if (target < nums[0]) {
        return binary_search(nums, index, last_index, target);
    }

    return binary_search(nums, 0, index, target);
}

int search2(const std::vector<int> &nums, int target) {
    for (const auto n : nums) {
        if (n == target) {
            return true;
        }
    }
    return false;
}

int main() {
    assert((pivot_index(std::vector<int>{2, 5, 6, 0, 0, 1, 2}) == 3));
    assert((pivot_index(std::vector<int>{1, 1}) == 0));
    // assert((pivot_index(std::vector<int>{1, 3, 1, 1, 1}) == 2));

    assert((search(std::vector<int>{2, 5, 6, 0, 0, 1, 2}, 0)));
    assert((!search(std::vector<int>{2, 5, 6, 0, 0, 1, 2}, 3)));

    assert((!search(std::vector<int>{1, 1}, 0)));
    return 0;
}
