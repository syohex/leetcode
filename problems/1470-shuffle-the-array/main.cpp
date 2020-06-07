#include <cassert>
#include <vector>

std::vector<int> shuffle(const std::vector<int> &nums, int n) {
    std::vector<int> ret;
    ret.resize(nums.size());

    int base = nums.size() / 2;
    for (int i = 0; i < n; ++i) {
        ret[i * 2] = nums[i];
        ret[i * 2 + 1] = nums[base + i];
    }
    return ret;
}

int main() {
    assert((shuffle(std::vector<int>{2, 5, 1, 3, 4, 7}, 3) == std::vector<int>{2, 3, 5, 4, 1, 7}));
    assert((shuffle(std::vector<int>{1, 2, 3, 4, 4, 3, 2, 1}, 4) == std::vector<int>{1, 4, 2, 3, 3, 2, 4, 1}));
    assert((shuffle(std::vector<int>{1, 1, 2, 2}, 2) == std::vector<int>{1, 2, 1, 2}));
    return 0;
}
