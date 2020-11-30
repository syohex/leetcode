#include <cassert>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

bool canJump(std::vector<int> &nums) {
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

        nums[pos] = -1;

        if (moves == 0) {
            continue;
        }

        for (int i = 1; i <= moves; ++i) {
            if (nums[pos + i] > 0) {
                pos_candidates.push(pos + i);
            }
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
    {
        std::vector<int> nums{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
        assert(canJump(nums));
    }
    {
        std::vector<int> nums{2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5,
                              3, 1, 2, 2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0,
                              7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9,
                              1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
        assert(!canJump(nums));
    }
    return 0;
}
