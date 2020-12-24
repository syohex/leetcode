#include <cassert>
#include <vector>

int singleNumber(const std::vector<int> &nums) {
    int val = 0;
    for (int num : nums) {
        val ^= num;
    }
    return val;
}

int main() {
    assert((singleNumber(std::vector<int>{2, 2, 1}) == 1));
    assert((singleNumber(std::vector<int>{4, 1, 2, 1, 2}) == 4));
    assert((singleNumber(std::vector<int>{1}) == 1));
    return 0;
}
