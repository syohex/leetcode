#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

long long minimumTime(std::vector<int> &time, int totalTrips) {
    const auto check = [](const std::vector<int> &time, long long trips, long long totalTrips) {
        long long tmp = 0;
        for (int t : time) {
            tmp += trips / t;
        }

        return tmp >= totalTrips;
    };

    std::sort(time.begin(), time.end());

    long long left = 1;
    long long right = static_cast<long long>(time.back()) * static_cast<long long>(totalTrips);
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (check(time, mid, totalTrips)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> time{1, 2, 3};
        auto ret = minimumTime(time, 5);
        assert(ret == 3);
    }
    {
        std::vector<int> time{2};
        auto ret = minimumTime(time, 1);
        assert(ret == 2);
    }
    return 0;
}
