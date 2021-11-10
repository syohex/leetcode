#include <cassert>
#include <vector>

int maxProfit(const std::vector<int> &prices) {
    int ret = 0;
    int limit = prices.size();
    int i = 0;
    while (i < limit) {
        while (i < limit - 1 && prices[i] > prices[i + 1]) {
            ++i;
        }

        int low = prices[i];
        while (i < limit - 1 && prices[i] < prices[i + 1]) {
            ++i;
        }

        int high = prices[i];
        ret += high - low;
        ++i;
    }

    return ret;
}

int main() {
    {
        std::vector<int> prices{7, 1, 5, 3, 6, 4};
        assert(maxProfit(prices) == 7);
    }
    {
        std::vector<int> prices{1, 2, 3, 4, 5};
        assert(maxProfit(prices) == 4);
    }
    {
        std::vector<int> prices{7, 6, 4, 3, 1};
        assert(maxProfit(prices) == 0);
    }
    return 0;
}