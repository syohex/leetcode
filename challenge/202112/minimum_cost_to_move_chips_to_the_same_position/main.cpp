#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int minCostToMoveChips(const std::vector<int> &chips) {
    int ret = INT_MAX;
    int len = chips.size();
    for (int i = 0; i < len; ++i) {
        int sum = 0;
        for (int j = 0; j < len; ++j) {
            if (i == j) {
                continue;
            }

            int diff = std::abs(chips[i] - chips[j]);
            if (diff % 2 != 0) {
                sum += 1;
            }
        }

        ret = std::min(ret, sum);
    }

    return ret;
}

int main() {
    {
        std::vector<int> chips{1, 2, 3};
        assert(minCostToMoveChips(chips) == 1);
    }
    {
        std::vector<int> chips{2, 2, 2, 3, 3};
        assert(minCostToMoveChips(chips) == 2);
    }
    {
        std::vector<int> chips{1, 1000000000};
        assert(minCostToMoveChips(chips) == 1);
    }
    return 0;
}
