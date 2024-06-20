#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

int maxDistance(std::vector<int> &position, int m) {
    const auto check = [&](int force) {
        int prev = position[0];
        int count = 1;
        for (std::size_t i = 1; i < position.size(); ++i) {
            if (position[i] - prev >= force) {
                prev = position[i];
                ++count;
                if (count >= m) {
                    return true;
                }
            }
        }

        return false;
    };

    std::sort(position.begin(), position.end());

    int left = 1;
    int right = std::ceil((position.back() - position.front()) / (static_cast<double>(m) - 1));
    int ret = right + 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ret = mid;
        } else {
            right = mid - 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> position{1, 2, 3, 4, 7};
        int ret = maxDistance(position, 3);
        assert(ret == 3);
    }
    {
        std::vector<int> position{5, 4, 3, 2, 1, 1000000000};
        int ret = maxDistance(position, 2);
        assert(ret == 999999999);
    }
    return 0;
}
