#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
    std::sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    });

    std::vector<int> dp;
    for (const auto &e : envelopes) {
        size_t pos = std::lower_bound(dp.begin(), dp.end(), e[1]) - dp.begin();
        if (pos == dp.size()) {
            dp.push_back(e[1]);
        } else {
            dp[pos] = e[1];
        }
    }

    return dp.size();
}

int main() {
    {
        std::vector<std::vector<int>> envelopes{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
        auto ret = maxEnvelopes(envelopes);
        assert(ret == 3);
    }
    {
        std::vector<std::vector<int>> envelopes{{1, 1}, {1, 1}, {1, 1}};
        auto ret = maxEnvelopes(envelopes);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<int>> envelopes{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400},
                                                {5, 250}, {6, 370}, {7, 360}, {7, 380}};
        auto ret = maxEnvelopes(envelopes);
        assert(ret == 5);
    }
    return 0;
}