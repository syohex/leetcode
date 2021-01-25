#include <cassert>
#include <vector>

bool kLengthApart(const std::vector<int> &nums, int k) {
    size_t last_one = nums.size();
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            last_one = i;
            break;
        }
    }

    if (last_one == nums.size()) {
        return true;
    }

    for (size_t i = last_one + 1; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            size_t diff = i - last_one - 1;
            if (diff < k) {
                return false;
            }

            last_one = i;
        }
    }

    return true;
}

int main() {
    assert((kLengthApart(std::vector<int>{1, 0, 0, 0, 1, 0, 0, 1}, 2)));
    assert((!kLengthApart(std::vector<int>{1, 0, 0, 1, 0, 1}, 2)));
    assert((kLengthApart(std::vector<int>{1, 1, 1, 1, 1}, 0)));
    assert((kLengthApart(std::vector<int>{0, 1, 0, 1}, 1)));
}
