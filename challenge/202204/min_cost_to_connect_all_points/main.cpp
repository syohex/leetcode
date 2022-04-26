#include <cassert>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

int minCostConnectPoints(const std::vector<std::vector<int>> &points) {
    struct Data {
        int distance;
        int x;
        int y;
        size_t index;
    };

    const auto cmp = [](const Data &a, const Data &b) { return a.distance > b.distance; };

    size_t len = points.size();
    size_t n = 0;

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({0, points[0][0], points[0][1], 0});

    std::set<size_t> checked;

    int ret = 0;
    while (n < len) {
        Data d = q.top();
        q.pop();

        if (checked.find(d.index) != checked.end()) {
            continue;
        }

        ++n;
        checked.insert(d.index);
        ret += d.distance;

        for (size_t i = 0; i < len; ++i) {
            if (checked.find(i) == checked.end()) {
                int x = points[i][0];
                int y = points[i][1];

                int dist = std::abs(x - d.x) + std::abs(y - d.y);
                q.push({dist, x, y, i});
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
        assert(minCostConnectPoints(points) == 20);
    }
    {
        std::vector<std::vector<int>> points{{3, 12}, {-2, 5}, {-4, 1}};
        assert(minCostConnectPoints(points) == 18);
    }
    return 0;
}