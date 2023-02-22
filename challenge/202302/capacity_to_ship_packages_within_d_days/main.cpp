#include <cassert>
#include <vector>
#include <algorithm>

int shipWithinDays(const std::vector<int> &weights, int days) {
    const auto can_ship = [&](int capacity) -> bool {
        int weight = 0;
        int total_days = 1;
        for (int w : weights) {
            weight += w;
            if (weight > capacity) {
                total_days += 1;
                weight = w;
            }
        }

        return total_days <= days;
    };

    int max_weight = 0;
    int total_weight = 0;
    for (int weight : weights) {
        total_weight += weight;
        max_weight = std::max(max_weight, weight);
    }

    int left = max_weight;
    int right = total_weight;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (can_ship(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int days = 5;
        int ret = shipWithinDays(weights, days);
        assert(ret == 15);
    }
    {
        std::vector<int> weights{3, 2, 2, 4, 1, 4};
        int days = 3;
        int ret = shipWithinDays(weights, days);
        assert(ret == 6);
    }
    {
        std::vector<int> weights{1, 2, 3, 1, 1};
        int days = 4;
        int ret = shipWithinDays(weights, days);
        assert(ret == 3);
    }
    return 0;
}
