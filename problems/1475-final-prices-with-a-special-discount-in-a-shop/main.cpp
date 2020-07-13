#include <cassert>
#include <vector>

std::vector<int> finalPrices(const std::vector<int> &prices) {
    std::vector<int> ret(prices.size());
    ret[prices.size() - 1] = prices.back();

    for (size_t i = 0; i < prices.size() - 1; ++i) {
        bool found = false;
        int min = prices[i];
        for (size_t j = i + 1; j < prices.size(); ++j) {
            if (prices[j] <= min) {
                found = true;
                min = prices[j];
                break;
            }
        }

        if (!found) {
            ret[i] = prices[i];
            continue;
        }

        ret[i] = prices[i] - min;
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{8, 4, 6, 2, 3};
        auto ret = finalPrices(input);
        assert((ret == std::vector<int>{4, 2, 4, 2, 3}));
    }
    {
        std::vector<int> input{1, 2, 3, 4, 5};
        auto ret = finalPrices(input);
        assert((ret == std::vector<int>{1, 2, 3, 4, 5}));
    }
    {
        std::vector<int> input{10, 1, 1, 6};
        auto ret = finalPrices(input);
        assert((ret == std::vector<int>{9, 0, 1, 6}));
    }
    {
        std::vector<int> input{4, 7, 1, 9, 4, 8, 8, 9, 4};
        auto ret = finalPrices(input);
        assert((ret == std::vector<int>{3, 6, 1, 5, 0, 0, 4, 5, 4}));
    }
    return 0;
}
