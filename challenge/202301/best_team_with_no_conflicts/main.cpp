#include <cassert>
#include <vector>
#include <algorithm>

int bestTeamScore(const std::vector<int> &scores, const std::vector<int> &ages) {
    int len = scores.size();
    std::vector<std::pair<int, int>> age_scores;
    for (int i = 0; i < len; ++i) {
        age_scores.push_back({ages[i], scores[i]});
    }

    // sort by age
    std::sort(age_scores.begin(), age_scores.end());

    std::vector<int> dp(len, 0);
    for (int i = 0; i < len; ++i) {
        dp[i] = age_scores[i].second;
    }

    int ret = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (age_scores[i].second >= age_scores[j].second) {
                dp[i] = std::max(dp[i], dp[j] + age_scores[i].second);
            }
        }
        ret = std::max(ret, dp[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> scores{1, 3, 5, 10, 15};
        std::vector<int> ages{1, 2, 3, 4, 5};
        int ret = bestTeamScore(scores, ages);
        assert(ret == 34);
    }
    {
        std::vector<int> scores{4, 5, 6, 5};
        std::vector<int> ages{2, 1, 2, 1};
        int ret = bestTeamScore(scores, ages);
        assert(ret == 16);
    }
    {
        std::vector<int> scores{1, 2, 3, 5};
        std::vector<int> ages{8, 9, 10, 1};
        int ret = bestTeamScore(scores, ages);
        assert(ret == 6);
    }
    {
        std::vector<int> scores{1};
        std::vector<int> ages{4};
        int ret = bestTeamScore(scores, ages);
        assert(ret == 1);
    }
    return 0;
}
