#include <cassert>
#include <vector>
#include <algorithm>

int minEatingSpeed(const std::vector<int> &piles, int h) {
    int left = 1;
    int right = *std::max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int pile : piles) {
            sum += pile / mid;
            if (pile % mid != 0) {
                sum += 1;
            }
        }

        if (sum <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

int main() {
    {
        std::vector<int> piles{3, 6, 7, 11};
        assert(minEatingSpeed(piles, 8) == 4);
    }
    {
        std::vector<int> piles{30, 11, 23, 4, 20};
        assert(minEatingSpeed(piles, 5) == 30);
    }
    {
        std::vector<int> piles{30, 11, 23, 4, 20};
        assert(minEatingSpeed(piles, 6) == 23);
    }
    return 0;
}