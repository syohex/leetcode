#include <cassert>
#include <vector>
#include <algorithm>

int maxProfix(const std::vector<int> &prices) {
    int sold = 0;
    int hold = -prices[0];
    int amount = 0;

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
        int ret = maxProfix(prices);
        assert(ret == 3);
    }
    {
        std::vector<int> prices{1};
        int ret = maxProfix(prices);
        assert(ret == 0);
    }
    return 0;
}
