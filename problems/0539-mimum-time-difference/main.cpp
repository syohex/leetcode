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

    std::vector<int> minutes(60 * 24, 0);
    for (const auto &t : timePoints) {
        int min = to_minutes(t);
        if (minutes[min] != 0) {
            return 0;
        }

        ++minutes[to_minutes(t)];
    }

    constexpr int one_day = 60 * 24;
    constexpr int half_day = 60 * 12;
    int ret = INT_MAX;

    int first = -1;
    int prev = 0;
    for (int i = 0; i < 1440; ++i) {
        if (minutes[i] == 0) {
            continue;
        }
        if (first == -1) {
            first = i;
            prev = i;
        } else {
            int diff = std::abs(i - prev);
            if (diff >= half_day) {
                diff = one_day - diff;
            }

            ret = std::min(ret, diff);
            prev = i;
        }
    }

    int diff = std::abs(prev - first);
    if (diff >= half_day) {
        diff = one_day - diff;
    }
    return std::min(ret, diff);
}

int main() {
    {
        std::vector<std::string> input{"23:59", "00:00"};
        assert(findMinDifference(input) == 1);
    }
    {
        std::vector<std::string> input{"01:01", "02:02"};
        assert(findMinDifference(input) == 61);
    }
    {
        std::vector<std::string> input{"00:00", "23:59", "00:00"};
        assert(findMinDifference(input) == 0);
    }
    return 0;
}
