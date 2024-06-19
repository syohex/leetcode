#include <cassert>
#include <vector>
#include <algorithm>

int minDays(const std::vector<int> &bloomDay, int m, int k) {
    int max_days = *std::max_element(bloomDay.begin(), bloomDay.end());

    int left = 0;
    int right = max_days;

    int ret = max_days + 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        int bouquets = 0;
        for (int b : bloomDay) {
            if (b <= mid) {
                ++count;
            } else {
                count = 0;
            }

            if (count == k) {
                count = 0;
                ++bouquets;
            }
        }

        if (bouquets >= m) {
            right = mid - 1;
            ret = mid;
        } else {
            left = mid + 1;
        }
    }

    return ret == max_days + 2 ? -1 : ret;
}

int main() {
    {
        std::vector<int> bloomDay{1, 10, 3, 10, 2};
        int ret = minDays(bloomDay, 3, 1);
        assert(ret == 3);
    }
    {
        std::vector<int> bloomDay{1, 10, 3, 10, 2};
        int ret = minDays(bloomDay, 3, 2);
        assert(ret == -1);
    }
    {
        std::vector<int> bloomDay{7, 7, 7, 7, 12, 7, 7};
        int ret = minDays(bloomDay, 2, 3);
        assert(ret == 12);
    }
    return 0;
}
