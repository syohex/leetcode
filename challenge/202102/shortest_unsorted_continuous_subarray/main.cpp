#include <cassert>
#include <vector>
#include <algorithm>

int findUnsortedSubarray(const std::vector<int> &nums) {
    auto tmp = nums;
    std::sort(tmp.begin(), tmp.end());

    int len = nums.size();
    int start = len;
    for (int i = 0; i < len; ++i) {
        if (tmp[i] != nums[i]) {
            start = i;
            break;
        }
    }

    if (start == len) {
        return 0;
    }

    int end = len;
    for (int i = len - 1; i >= 0; --i) {
        if (tmp[i] != nums[i]) {
            end = i;
            break;
        }
    }

    return end - start + 1;
}

int main() {
    assert((findUnsortedSubarray(std::vector<int>{2, 6, 4, 8, 10, 9, 15}) == 5));
    assert((findUnsortedSubarray(std::vector<int>{15, 6, 4, 8, 10, 9, 2}) == 7));
    assert((findUnsortedSubarray(std::vector<int>{1, 2, 3, 4}) == 0));
    assert((findUnsortedSubarray(std::vector<int>{1}) == 0));
    return 0;
}
