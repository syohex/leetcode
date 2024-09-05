#include <cassert>
#include <vector>
#include <numeric>

std::vector<int> missingRolls(const std::vector<int> &rolls, int mean, int n) {
    int len = rolls.size();
    int sum = std::accumulate(rolls.begin(), rolls.end(), 0);

    int real_sum = mean * (len + n);
    int diff = real_sum - sum;
    if (diff < n || diff > n * 6) {
        return {};
    }

    std::vector<int> ret(n, 0);
    int v = diff / n;
    int m = diff % n;
    for (int i = 0; i < n; ++i) {
        ret[i] = v;
        if (m > 0) {
            ++ret[i];
            --m;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> rolls{3, 2, 4, 3};
        std::vector<int> expected{6, 6};
        auto ret = missingRolls(rolls, 4, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> rolls{1, 5, 6};
        std::vector<int> expected{3, 2, 2, 2};
        auto ret = missingRolls(rolls, 3, 4);
        assert(ret == expected);
    }
    {
        std::vector<int> rolls{1, 2, 3, 4};
        std::vector<int> expected{};
        auto ret = missingRolls(rolls, 6, 4);
        assert(ret == expected);
    }
    {
        std::vector<int> rolls{6, 3, 4, 3, 5, 3};
        std::vector<int> expected{};
        auto ret = missingRolls(rolls, 1, 6);
        assert(ret == expected);
    }
    return 0;
}