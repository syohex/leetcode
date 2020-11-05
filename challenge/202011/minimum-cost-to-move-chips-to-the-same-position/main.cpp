#include <cassert>
#include <vector>
#include <algorithm>

int minCostToMoveChips(const std::vector<int> &position) {
    int even = 0, odd = 0;
    for (size_t i = 0; i < position.size(); ++i) {
        if (i % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }

    return std::min(even, odd);
}

int main() {
    {
        std::vector<int> position{1, 2, 3};
        assert(minCostToMoveChips(position) == 1);
    }
    {
        std::vector<int> position{2, 2, 2, 3, 3};
        assert(minCostToMoveChips(position) == 2);
    }
    {
        std::vector<int> position{1, 10000000};
        assert(minCostToMoveChips(position) == 1);
    }
    return 0;
}
