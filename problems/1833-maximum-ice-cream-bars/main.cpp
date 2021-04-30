#include <cassert>
#include <vector>
#include <algorithm>

int maxIceCream(std::vector<int> &costs, int coins) {
    std::sort(costs.begin(), costs.end());
    int sum = 0;
    int len = costs.size();
    for (int i = 0; i < len; ++i) {
        if (sum + costs[i] > coins) {
            return i;
        }

        sum += costs[i];
    }

    return len;
}

int main() {
    {
        std::vector<int> costs{1, 3, 2, 4, 1};
        assert(maxIceCream(costs, 7) == 4);
    }
    {
        std::vector<int> costs{10, 6, 8, 7, 7, 8};
        assert(maxIceCream(costs, 5) == 0);
    }
    {
        std::vector<int> costs{1, 6, 3, 1, 2, 5};
        assert(maxIceCream(costs, 20) == 6);
    }
    {
        std::vector<int> costs{7, 3, 3, 6, 6, 6, 10, 5, 9, 2};
        assert(maxIceCream(costs, 56) == 9);
    }
    return 0;
}
