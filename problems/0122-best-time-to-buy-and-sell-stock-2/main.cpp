#include <cassert>
#include <vector>
#include <functional>

int maxProfit(const std::vector<int> &prices) {
    if (prices.size() == 1) {
        return 0;
    }

    int max = 0;
    std::function<void(int sum, bool isBuy, size_t index)> f;
    f = [&f, &prices, &max](int sum, bool isBuy, size_t index) {
        if (index >= prices.size()) {
            if (sum > max) {
                max = sum;
            }

            return;
        }

        if (isBuy) {
            f(sum - prices[index], false, index + 1);
            f(sum, isBuy, index + 1);
        } else {
            f(sum + prices[index], true, index + 1);
            f(sum, false, index + 1);
        }
    };

    f(0, true, 0);
    return max;
}

int main() {
    {
        std::vector<int> input{7, 1, 5, 3, 6, 4};
        assert(maxProfit(input) == 7);
    }
    {
        std::vector<int> input{1, 2, 3, 4, 5};
        assert(maxProfit(input) == 4);
    }
    {
        std::vector<int> input{7, 6, 4, 3, 1};
        assert(maxProfit(input) == 0);
    }
    return 0;
}
