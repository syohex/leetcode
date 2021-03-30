#include <cassert>
#include <vector>
#include <algorithm>

int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
    const auto cmp = [](const std::vector<int> &a, const std::vector<int> &b) -> bool {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }

        return a[0] < b[0];
    };

    std::sort(envelopes.begin(), envelopes.end(), cmp);

    std::vector<int> dp(envelopes.size(), 1);
    for (size_t i = 1; i < envelopes.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int ret = 0;
    for (int n : dp) {
        ret = std::max(ret, n);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> envelopes{
            {5, 4},
            {6, 4},
            {6, 7},
            {2, 3},
        };
        assert(maxEnvelopes(envelopes) == 3);
    }
    {
        std::vector<std::vector<int>> envelopes{
            {1, 1},
            {1, 1},
            {1, 1},
        };
        assert(maxEnvelopes(envelopes) == 1);
    }
    {
        std::vector<std::vector<int>> envelopes{
            {2, 100},
            {3, 200},
            {4, 300},
            {5, 500},
            {5, 400},
            {5, 250},
            {6, 370},
            {6, 360},
            {7, 380},
        };
        assert(maxEnvelopes(envelopes) == 5);
    }
    return 0;
}
