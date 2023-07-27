#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

long long maxRunTime(int n, const std::vector<int> &batteries) {
    long long sum = 0;
    for (int battery : batteries) {
        sum += battery;
    }

    long long left = 0;
    long long right = sum / n;

    while (left < right) {
        long long mid = right - (right - left) / 2;
        long long tmp = 0;

        for (int battery : batteries) {
            tmp += std::min(static_cast<long long>(battery), mid);
        }

        if (tmp >= mid * n) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> battries{3, 3, 3};
        auto ret = maxRunTime(2, battries);
        assert(ret == 4LL);
    }
    {
        std::vector<int> battries{1, 1, 1, 1};
        auto ret = maxRunTime(2, battries);
        assert(ret == 2LL);
    }
    return 0;
}
