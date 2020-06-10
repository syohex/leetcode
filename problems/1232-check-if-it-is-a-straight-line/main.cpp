#include <cassert>
#include <vector>
#include <cstdio>

bool checkStraightLine(const std::vector<std::vector<int>> &coordinates) {
    if (coordinates.size() == 2) {
        return true;
    }

    int xDiff = coordinates[1][0] - coordinates[0][0];
    if (xDiff == 0) {
        for (size_t i = 1; i < coordinates.size() - 1; ++i) {
            xDiff = coordinates[i + 1][0] - coordinates[i][0];
            if (xDiff != 0) {
                return false;
            }
        }

        return true;
    }

    double slope = (coordinates[1][1] - coordinates[0][1]) / static_cast<double>(xDiff);
    for (size_t i = 1; i < coordinates.size() - 1; ++i) {
        xDiff = coordinates[i + 1][0] - coordinates[i][0];
        if (xDiff == 0) {
            return false;
        }

        double s = (coordinates[i + 1][1] - coordinates[i][1]) / static_cast<double>(xDiff);
        if (slope != s) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7},
        };
        assert(checkStraightLine(input));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7},
        };
        assert(!checkStraightLine(input));
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0},
            {0, 1},
            {0, -1},
        };
        assert(checkStraightLine(input));
    }
    {
        std::vector<std::vector<int>> input{
            {2, 1},
            {4, 2},
            {6, 3},
        };
        assert(checkStraightLine(input));
    }
    return 0;
}
