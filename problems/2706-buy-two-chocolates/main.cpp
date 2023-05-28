#include <cassert>
#include <vector>
#include <algorithm>

int buyChoco(std::vector<int> &prices, int money) {
    std::sort(prices.begin(), prices.end());

    int orig = money;
    int count = 0;
    for (size_t i = 0; i < prices.size(); ++i) {
        if (money >= prices[i]) {
            count += 1;
            money -= prices[i];
            if (count == 2) {
                return money;
            }
        } else {
            break;
        }
    }

    return orig;
}

int main() {
    {
        std::vector<int> prices{1, 2, 2};
        int ret = buyChoco(prices, 3);
        assert(ret == 0);
    }
    {
        std::vector<int> prices{3, 2, 3};
        int ret = buyChoco(prices, 3);
        assert(ret == 3);
    }
    return 0;
}
