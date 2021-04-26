#include <cassert>
#include <vector>
#include <queue>

int furthestBuilding(const std::vector<int> &heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int len = heights.size();
    for (int i = 0; i < len - 1; ++i) {
        int diff = heights[i + 1] - heights[i];
        if (diff <= 0) {
            continue;
        }

        q.push(diff);
        if (q.size() <= ladders) {
            continue;
        }

        int min_diff = q.top();
        q.pop();
        bricks -= min_diff;
        if (bricks < 0) {
            return i;
        }
    }

    return len - 1;
}

int main() {
    {
        std::vector<int> heights{4, 2, 7, 6, 9, 14, 12};
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
