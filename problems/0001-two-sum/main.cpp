#include <cassert>
#include <vector>

std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return std::vector<int>{static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }

    return std::vector<int>{0, 0};
}

int main() {
    auto ret = twoSum(std::vector<int>{2, 7, 11, 15}, 9);
    assert(ret[0] == 0 && ret[1] == 1);

    ret = twoSum(std::vector<int>{2, 7, 11, 15}, 22);
    assert(ret[0] == 1 && ret[1] == 3);

    ret = twoSum(std::vector<int>{1, 9}, 10);
    assert(ret[0] == 0 && ret[1] == 1);

    ret = twoSum(std::vector<int>{1, 2, 3}, 4);
    assert(ret[0] == 0 && ret[1] == 2);

    ret = twoSum(std::vector<int>{2, 5, 5, 11}, 10);
    assert(ret[0] == 1 && ret[1] == 2);
    return 0;
}