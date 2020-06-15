#include <cassert>
#include <vector>

std::vector<int> decompressRLElist(const std::vector<int> &nums) {
    std::vector<int> ret;
    for (size_t i = 0; i < nums.size(); i += 2) {
        int len = nums[i];
        int num = nums[i + 1];

        for (int j = 0; j < len; ++j) {
            ret.push_back(num);
        }
    }

    return ret;
}

int main() {
    assert((decompressRLElist(std::vector<int>{1, 2, 3, 4}) == std::vector<int>{2, 4, 4, 4}));
    assert((decompressRLElist(std::vector<int>{1, 1, 2, 3}) == std::vector<int>{1, 3, 3}));
    return 0;
}
