#include <cassert>
#include <vector>
#include <cstdio>

int search(const std::vector<int> &nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> input{-1, 0, 3, 5, 9, 12};
        auto ret = search(input, 9);
        assert(ret == 4);
        assert(input[ret] == 9);
    }
    {
        std::vector<int> input{-1, 0, 3, 5, 9, 12};
        auto ret = search(input, 2);
        assert(ret == -1);
    }
    {
        std::vector<int> input{5};
        auto ret = search(input, 5);
        assert(ret == 0);
        assert(input[ret] == 5);
    }
    {
        std::vector<int> input{0, 1};
        auto ret = search(input, 0);
        assert(ret == 0);
        assert(input[ret] == 0);

        ret = search(input, 1);
        assert(ret == 1);
        assert(input[ret] == 1);
    }
    return 0;
}
