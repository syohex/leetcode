#include <cassert>
#include <vector>
#include <cstdio>
#include <functional>

int furthestBuilding(const std::vector<int> &heights, int bricks, int ladders) {
    if (heights.size() == 1) {
        return 1;
    }

    struct Diff {
        int diff = 0;
        size_t pos = 0;
    };

    std::vector<Diff> v;
    for (size_t i = 0; i < heights.size() - 1; ++i) {
        int diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            v.emplace_back(Diff{diff, i});
        }
    }

    int limit = static_cast<int>(heights.size() - 1);

    if (v.empty()) {
        return limit;
    }

    int max = v[0].pos;
    std::function<void(size_t pos, int bricks, int ladders)> f;
    f = [&f, &v, &limit, &max](size_t pos, int bricks, int ladders) {
        if (pos == v.size()) {
            max = limit;
            return;
        }

        if (ladders == 0 && bricks < v[pos].diff) {
            if (max < static_cast<int>(pos)) {
                max = v[pos].pos;
            }
        } else {
            if (bricks >= v[pos].diff) {
                f(pos + 1, bricks - v[pos].diff, ladders);
            }
            if (ladders > 0) {
                f(pos + 1, bricks, ladders - 1);
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
    {
        std::vector<int> heights{7, 5, 13};
        assert(furthestBuilding(heights, 0, 0) == 1);
    }
    return 0;
}
