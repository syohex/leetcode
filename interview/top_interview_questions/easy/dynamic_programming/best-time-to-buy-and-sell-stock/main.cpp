#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(const std::vector<int> &prices) {
    int min = INT_MAX;
    int max = 0;

    for (const auto price : prices) {
        min = std::min(min, price);
        max = std::max(max, price - min);
    }

    return max;
}

int main() {
    {
        std::vector<int> prices{7, 1, 5, 3, 6, 4};
        assert(maxProfit(prices) == 5);
    }
    {
        std::vector<int> prices{7, 6, 4, 3, 1};
        assert(maxProfit(prices) == 0);
    }
    return 0;
}
