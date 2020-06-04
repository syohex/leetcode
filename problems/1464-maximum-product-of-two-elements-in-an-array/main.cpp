#include <cassert>
#include <vector>

int maxProduct(const std::vector<int> &nums) {
    int ret = 0;

    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            int tmp = (nums[i] - 1) * (nums[j] - 1);
            if (tmp > ret) {
                ret = tmp;
            }
        }
    }

    return ret;
}

int main() {
    assert(maxProduct(std::vector<int>{3, 4, 5, 2}) == 12);
    assert(maxProduct(std::vector<int>{1, 5, 4, 5}) == 16);
    assert(maxProduct(std::vector<int>{3, 7}) == 12);
    return 0;
}