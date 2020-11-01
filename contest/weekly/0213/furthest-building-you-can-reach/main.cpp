#include <cassert>
#include <vector>
#include <cstdio>
#include <functional>

int furthestBuilding(const std::vector<int> &heights, int bricks, int ladders) {
    if (heights.size() == 1) {
        return 1;
    }

    int max = 0;
    std::function<void(size_t pos, int bricks, int ladders)> f;
    f = [&f, &heights, &max](size_t pos, int bricks, int ladders) {
        if (pos == heights.size() - 1) {
            max = heights.size() - 1;
            return;
        }

        int diff = heights[pos + 1] - heights[pos];
        if (diff <= 0) {
            f(pos + 1, bricks, ladders);
        } else {
            if (ladders == 0 && bricks < diff) {
                if (max < static_cast<int>(pos)) {
                    max = pos;
                }
            } else {
                if (bricks >= diff) {
                    f(pos + 1, bricks - diff, ladders);
                }
                if (ladders > 0) {
                    f(pos + 1, bricks, ladders - 1);
                }
            }
        }
    };

    f(0, bricks, ladders);
    return max;
}

int main() {
    {
        std::vector<int> heights{4, 2, 7, 6, 8, 14, 12};
        assert(furthestBuilding(heights, 5, 1) == 4);
    }
    {
        std::vector<int> heights{4, 12, 2, 7, 3, 18, 20, 3, 19};
        assert(furthestBuilding(heights, 10, 2) == 7);
    }
    {
        std::vector<int> heights{14, 3, 19, 3};
        assert(furthestBuilding(heights, 17, 0) == 3);
    }
    return 0;
}
