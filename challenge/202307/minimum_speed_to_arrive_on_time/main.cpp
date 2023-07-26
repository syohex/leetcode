#include <cassert>
#include <vector>
#include <cstdio>
#include <cmath>

int minSpeedOnTime(const std::vector<int> &dist, double hour) {
    const auto f = [&](double speed) -> double {
        double sum = 0;
        for (size_t i = 0; i < dist.size(); ++i) {
            double time = dist[i] / speed;
            if (i == dist.size() - 1) {
                sum += time;
            } else {
                sum += std::ceil(time);
            }
        }

        return sum;
    };

    int left = 0;
    int right = 10'000'000;
    int ret = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (f(mid) <= hour) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> dist{1, 3, 2};
        int ret = minSpeedOnTime(dist, 6.0);
        assert(ret == 1);
    }
    {
        std::vector<int> dist{1, 3, 2};
        int ret = minSpeedOnTime(dist, 2.7);
        assert(ret == 3);
    }
    {
        std::vector<int> dist{1, 3, 2};
        int ret = minSpeedOnTime(dist, 1.9);
        assert(ret == -1);
    }
    return 0;
}
