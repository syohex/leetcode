#include <cassert>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int> &prices) {
    int min = 1'000'000'000;
    int ret = 0;
    for (int price : prices) {
        min = std::min(min, price);
        ret = std::max(ret, price - min);
    }

    return ret;
}

int main() {
    {
        std::vector<int> prices{7, 1, 5, 3, 6, 4};
        int ret = maxProfit(prices);
        assert(ret == 5);
    }
    {
        std::vector<int> prices{7, 6, 4, 3, 1};
        int ret = maxProfit(prices);
        assert(ret == 0);
    }
    return 0;
}
