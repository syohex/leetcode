#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

bool canJump(const std::vector<int> &nums) {
    std::vector<bool> ok(nums.size(), false);
    ok.back() = true;

    int limit = nums.size();
    for (int i = limit - 2; i >= 0; --i) {
        int max_jump = std::min(i + nums[i], limit - 1);
        for (int j = i + 1; j <= max_jump; ++j) {
            if (ok[j]) {
                ok[i] = true;
                break;
            }
        }
    }

    return ok[0];
}

int main() {
    assert((canJump(std::vector<int>{2, 3, 1, 1, 4})));
    assert((!canJump(std::vector<int>{3, 2, 1, 0, 4})));
    return 0;
}
