#include <cassert>
#include <vector>

int minTimeToVisitAllPoints(const std::vector<std::vector<int>> &points) {
    int ret = 0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        int diffX = points[i][0] < points[i + 1][0] ? points[i + 1][0] - points[i][0] : points[i][0] - points[i + 1][0];
        int diffY = points[i][1] < points[i + 1][1] ? points[i + 1][1] - points[i][1] : points[i][1] - points[i + 1][1];

        if (diffX > diffY) {
            ret += diffX;
        } else {
            ret += diffY;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 1},
            {3, 4},
            {-1, 0},
        };
        assert(minTimeToVisitAllPoints(input) == 7);
    }
    {
        std::vector<std::vector<int>> input{
            {3, 2},
            {-2, 2},
        };
        assert(minTimeToVisitAllPoints(input) == 5);
    }
    return 0;
}
