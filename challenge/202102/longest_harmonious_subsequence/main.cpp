#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int findLHS(const std::vector<int> &nums) {
    int ret = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        int sames = 1;
        int incs = 0;
        int decs = 0;
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] == nums[j]) {
                ++sames;
            } else if (nums[i] + 1 == nums[j]) {
                ++incs;
            } else if (nums[i] - 1 == nums[j]) {
                ++decs;
            }
        }

        if (!(incs == 0 && decs == 0)) {
            ret = std::max(ret, sames + std::max(incs, decs));
        }
    }

    return ret;
}

int main() {
    assert((findLHS(std::vector<int>{1, 3, 2, 2, 5, 2, 3, 7}) == 5));
    assert((findLHS(std::vector<int>{1, 2, 3, 4}) == 2));
    assert((findLHS(std::vector<int>{1, 1, 1, 1}) == 0));
    assert((findLHS(std::vector<int>{1, 2, 2, 1}) == 4));
    assert((findLHS(std::vector<int>{-3, -1, -1, -1, -3, -2}) == 4));

    {
        std::vector<int> input{2, 2, 2, 2, 2, 2, 2, 3, 1, 0, 0, 0, 3, 1, -1, 0, 1, 1, 0, 0, 1, 1, 2, 2, 2, 0, 1, 2, 2, 3, 2};
        assert(findLHS(input) == 20);
    }
    return 0;
}
