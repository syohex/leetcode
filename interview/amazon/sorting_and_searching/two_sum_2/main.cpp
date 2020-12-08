#include <cassert>
#include <vector>

std::vector<int> twoSum(const std::vector<int> &numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size() - 1);
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return std::vector<int>{left + 1, right + 1};
        }
        if (sum > target) {
            --right;
        } else {
            ++left;
        }
    }

    return std::vector<int>{};
}

int main() {
    {
        std::vector<int> numbers{2, 7, 11, 15};
        assert((twoSum(numbers, 9) == std::vector<int>{1, 2}));
    }
    {
        std::vector<int> numbers{2, 3, 4};
        assert((twoSum(numbers, 6) == std::vector<int>{1, 3}));
    }
    {
        std::vector<int> numbers{-1, 0};
        assert((twoSum(numbers, -1) == std::vector<int>{1, 2}));
    }
    return 0;
}
