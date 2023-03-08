#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

int minEatingSpeed(std::vector<int> &piles, int h) {
    const auto check = [](const std::vector<int> &piles, int64_t bananas, int64_t h) -> bool {
        int64_t hours = 0;
        for (int pile : piles) {
            hours += std::ceil(static_cast<double>(pile) / bananas);
        }
        return hours <= h;
    };

    std::sort(piles.begin(), piles.end());

    int64_t left = 1;
    int64_t right = piles.back();

    while (left < right) {
        int64_t mid = left + (right - left) / 2;
        if (check(piles, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> piles{3, 6, 7, 11};
        int ret = minEatingSpeed(piles, 8);
        assert(ret == 4);
    }
    {
        std::vector<int> piles{30, 11, 23, 4, 20};
        int ret = minEatingSpeed(piles, 5);
        assert(ret == 30);
    }
    {
        std::vector<int> piles{30, 11, 23, 4, 20};
        int ret = minEatingSpeed(piles, 6);
        assert(ret == 23);
    }
    return 0;
}
