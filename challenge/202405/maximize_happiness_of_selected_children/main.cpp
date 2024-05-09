#include <cassert>
#include <vector>
#include <algorithm>

long long maximumHappinessSum(std::vector<int> &happiness, int k) {
    std::sort(happiness.begin(), happiness.end(), std::greater<int>{});

    long long ret = 0;
    long long diff = 0;
    int i = 0;
    while (k > 0) {
        long long v = happiness[i] - diff;
        if (v <= 0) {
            break;
        }

        ret += v;
        ++diff;
        ++i;
        --k;
    }

    return ret;
}

int main() {
    {
        std::vector<int> happiness{1, 2, 3};
        auto ret = maximumHappinessSum(happiness, 2);
        assert(ret == 4);
    }
    {
        std::vector<int> happiness{1, 1, 1, 1};
        auto ret = maximumHappinessSum(happiness, 2);
        assert(ret == 1);
    }
    {
        std::vector<int> happiness{2, 3, 4, 5};
        auto ret = maximumHappinessSum(happiness, 1);
        assert(ret == 5);
    }
    return 0;
}
