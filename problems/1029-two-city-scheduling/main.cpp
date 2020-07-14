#include <cassert>
#include <vector>
#include <climits>
#include <functional>

int twoCitySchedCost(const std::vector<std::vector<int>> &costs) {
    int ret = INT_MAX;
    size_t limit = costs.size();

    std::function<void(size_t index, int sum, int numA, int numB)> f;
    f = [&f, &ret, &costs, &limit](size_t index, int sum, int numA, int numB) {
        if (sum > ret) {
            return;
        }

        if (index >= limit) {
            if (ret > sum) {
                ret = sum;
            }

            return;
        }

        if (numA > 0) {
            f(index + 1, sum + costs[index][0], numA - 1, numB);
        }
        if (numB > 0) {
            f(index + 1, sum + costs[index][1], numA, numB - 1);
        }
    };

    int count = static_cast<int>(costs.size() / 2);
    f(0, 0, count, count);
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {10, 20},
            {30, 200},
            {400, 50},
            {30, 20},
        };
        assert(twoCitySchedCost(input) == 110);
    }
    return 0;
}
