#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int maxProfit(int k, const std::vector<int> &prices) {
    int max = 0;
    std::function<void(size_t idx, int sum, int transactions, bool is_buy)> f;
    f = [&f, &prices, &max, &k](size_t idx, int sum, int transactions, bool is_buy) {
        if (transactions == k || idx >= prices.size()) {
            if (max < sum) {
                max = sum;
            }

            return;
        }

        if (is_buy) {
            f(idx + 1, sum - prices[idx], transactions, false);
        } else {
            f(idx + 1, sum + prices[idx], transactions + 1, true);
        }

        f(idx + 1, sum, transactions, is_buy);
    };

    f(0, 0, 0, true);
    return max;
}

int main() {
    {
        std::vector<int> prices{2, 4, 1};
        assert(maxProfit(2, prices) == 2);
    }
    {
        std::vector<int> prices{1, 2, 4};
        assert(maxProfit(2, prices) == 3);
    }
    {
        std::vector<int> prices{3, 2, 6, 5, 0, 3};
        assert(maxProfit(2, prices) == 7);
    }
    return 0;
}
