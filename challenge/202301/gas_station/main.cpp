#include <cassert>
#include <vector>
#include <cstddef>

int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost) {
    int total = 0;
    int current = 0;

    int ret = 0;
    for (size_t i = 0; i < gas.size(); ++i) {
        total += gas[i] - cost[i];
        current += gas[i] - cost[i];

        if (current < 0) {
            ret = i + 1;
            current = 0;
        }
    }

    if (total < 0) {
        return -1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> gas{1, 2, 3, 4, 5};
        std::vector<int> cost{3, 4, 5, 1, 2};
        int ret = canCompleteCircuit(gas, cost);
        assert(ret == 3);
    }
    {
        std::vector<int> gas{2, 3, 4};
        std::vector<int> cost{3, 4, 3};
        int ret = canCompleteCircuit(gas, cost);
        assert(ret == -1);
    }
    return 0;
}
