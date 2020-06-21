#include <cassert>
#include <vector>

std::vector<int> twoSum(const std::vector<int> &numbers, int target) {
    int limit = static_cast<int>(numbers.size());
    for (int i = 0; i < limit - 1; ++i) {
        for (int j = i + 1; j < limit; ++j) {
            int add = numbers[i] + numbers[j];
            if (add == target) {
                return std::vector<int>{i + 1, j + 1};
            } else if (add > target) {
                break;
            }
        }
    }

    return std::vector<int>{};
}

int main() {
    {
        std::vector<int> input{2, 7, 11, 15};
        auto ret = twoSum(input, 9);
        assert((ret == std::vector<int>{1, 2}));
    }
    {
        std::vector<int> input{0, 0, 1, 2};
        auto ret = twoSum(input, 0);
        assert((ret == std::vector<int>{1, 2}));
    }
    return 0;
}
