#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

int findMinDifference(const std::vector<std::string> &timePoints) {
    const auto to_minutes = [](const std::string &str) -> int {
        int hours = ((str[0] - '0') * 10) + str[1] - '0';
        int min = ((str[3] - '0') * 10) + str[4] - '0';
        return hours * 60 + min;
    };

    std::vector<int> times;
    for (const auto &t : timePoints) {
        times.push_back(to_minutes(t));
    }

    constexpr int one_day = 60 * 24;
    constexpr int half_day = 60 * 12;
    int ret = INT_MAX;
    for (size_t i = 0; i < times.size() - 1; ++i) {
        for (size_t j = i + 1; j < times.size(); ++j) {
            int diff = std::abs(times[i] - times[j]);
            if (diff >= half_day) {
                diff = one_day - diff;
            }

            ret = std::min(ret, diff);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> input{"23:59", "00:00"};
        assert(findMinDifference(input) == 1);
    }
    {
        std::vector<std::string> input{"00:00", "23:59", "00:00"};
        assert(findMinDifference(input) == 0);
    }
    return 0;
}
