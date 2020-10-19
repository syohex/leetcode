#include <cassert>
#include <numeric>
#include <functional>
#include <vector>
#include <cstdio>

int validate(const std::vector<size_t> &acc, const std::vector<int> &scores, const std::vector<int> &ages) {
    for (size_t i = 0; i < acc.size(); ++i) {
        int score_i = scores[acc[i]];
        int age_i = ages[acc[i]];
        for (size_t j = 0; j < acc.size(); ++j) {
            if (i == j) {
                continue;
            }
            int score_j = scores[acc[j]];
            int age_j = ages[acc[j]];
            if (score_i < score_j && age_i > age_j) {
                return false;
            }
        }
    }

    return true;
}

int bestTeamScore(const std::vector<int> &scores, const std::vector<int> &ages) {
    int max = 0;
    std::function<void(size_t idx, const std::vector<size_t> &acc)> f;
    f = [&f, &scores, &ages, &max](size_t idx, const std::vector<size_t> &acc) {
        if (idx >= scores.size()) {
            if (acc.empty()) {
                return;
            }

            if (acc.size() == 1) {
                if (scores[acc[0]] > max) {
                    max = scores[acc[0]];
                }
                return;
            }

            int sum = 0;
            for (size_t i = 0; i < acc.size(); ++i) {
                sum += scores[acc[i]];
            }

            if (sum > max) {
                max = sum;
            }
            return;
        }

        auto tmp = acc;
        tmp.push_back(idx);
        if (validate(tmp, scores, ages)) {
            f(idx + 1, tmp);
        }

        f(idx + 1, acc);
    };

    f(0, std::vector<size_t>{});
    return max;
}

int main() {
    {
        std::vector<int> scores{1, 3, 5, 10, 15};
        std::vector<int> ages{1, 2, 3, 4, 5};
        assert(bestTeamScore(scores, ages) == 34);
    }
    {
        std::vector<int> scores{4, 5, 6, 5};
        std::vector<int> ages{2, 1, 2, 1};
        assert(bestTeamScore(scores, ages) == 16);
    }
    {
        std::vector<int> scores{1, 2, 3, 5};
        std::vector<int> ages{8, 9, 10, 1};
        assert(bestTeamScore(scores, ages) == 6);
    }
    {
        std::vector<int> scores{9, 2, 8, 8, 2};
        std::vector<int> ages{4, 1, 3, 3, 5};
        assert(bestTeamScore(scores, ages) == 27);
    }
    return 0;
}
