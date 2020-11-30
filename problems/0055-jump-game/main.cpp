#include <cassert>
#include <vector>
#include <stack>

bool canJump(const std::vector<int> &nums) {
    size_t end = nums.size() - 1;
    std::stack<size_t> pos_candidates;
    pos_candidates.push(0);

    while (!pos_candidates.empty()) {
        size_t pos = pos_candidates.top();
        pos_candidates.pop();

        int moves = nums[pos];
        if (pos + moves >= end) {
            return true;
        }

        if (moves == 0) {
            continue;
        }

        for (int i = 1; i <= moves; ++i) {
            pos_candidates.push(pos + i);
        }
    }

    return false;
}

int main() {
    {
        std::vector<int> nums{2, 3, 1, 1, 4};
        assert(canJump(nums));
    }
    {
        std::vector<int> nums{3, 2, 1, 0, 4};
        assert(!canJump(nums));
    }
    return 0;
}
