#include <cassert>
#include <vector>
#include <cstdio>

int countNegatives(const std::vector<std::vector<int>> &grid) {
    size_t rows = grid.size();
    size_t columns = grid[0].size();

    int ret = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (grid[i][j] < 0) {
                ret += (rows - i) * (columns - j);
                columns -= (columns - j);
                break;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {4, 3, 2, -1},
            {3, 2, 1, -1},
            {1, 1, -1, -2},
            {-1, -1, -2, -3},
        };
        assert(countNegatives(input) == 8);
    }
    {
        std::vector<std::vector<int>> input{
            {3, 2},
            {1, 0},
        };
        assert(countNegatives(input) == 0);
    }
    {
        std::vector<std::vector<int>> input{
            {1, -1},
            {-1, -1},
        };
        assert(countNegatives(input) == 3);
    }
    {
        std::vector<std::vector<int>> input{
            {-1},
        };
        assert(countNegatives(input) == 1);
    }
    {
        std::vector<std::vector<int>> input{
            {3, 2},
            {-3, -3},
            {-3, -3},
            {-3, -3},
        };
        assert(countNegatives(input) == 6);
    }
    return 0;
}
