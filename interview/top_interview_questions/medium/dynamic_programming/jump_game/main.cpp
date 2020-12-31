#include <cassert>
#include <vector>
#include <cstdio>

bool canJump(const std::vector<int> &nums) {
    int limit = nums.size() - 1;
    int can_jump_last_pos = limit;
    for (int i = limit - 1; i >= 0; --i) {
        if (i + nums[i] >= can_jump_last_pos) {
            can_jump_last_pos = i;
        }
    }

    return can_jump_last_pos == 0;
}

int main() {
    assert((canJump(std::vector<int>{2, 3, 1, 1, 4})));
    assert((!canJump(std::vector<int>{3, 2, 1, 0, 4})));
    return 0;
}
