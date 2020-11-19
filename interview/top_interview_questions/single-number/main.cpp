#include <cassert>
#include <vector>

int singleNumber(const std::vector<int> &nums) {
    int ret = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        ret ^= nums[i];
    }

    return ret;
}

int main() {
    assert((singleNumber(std::vector<int>{2, 2, 1}) == 1));
    assert((singleNumber(std::vector<int>{4, 1, 2, 1, 2}) == 4));
    assert((singleNumber(std::vector<int>{1}) == 1));
    return 0;
}
