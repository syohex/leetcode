#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(const std::vector<int> &prices) {
    int amount = 0;
    int hold = -prices[0];
    int sold = 0;

    for (size_t i = 1; i < prices.size(); ++i) {
        int tmp = sold;

        sold = hold + prices[i];
        hold = std::max(hold, amount - prices[i]);
        amount = std::max(amount, tmp);
    }

    return std::max(amount, sold);
}

int main() {
    {
        std::vector<int> prices{1, 2, 3, 0, 2};
        assert(maxProfit(prices) == 3);
    }
    {
        std::vector<int> prices{0};
        assert(maxProfit(prices) == 0);
    }
    return 0;
}