#include <cassert>
#include <vector>

bool canMakeSquare(const std::vector<std::vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            int whites = 0;
            int blacks = 0;
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    if (grid[i + x][j + y] == 'W') {
                        ++whites;
                    } else {
                        ++blacks;
                    }
                }
            }

            if (whites >= 3 || blacks >= 3) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    {
        std::vector<std::vector<char>> grid{{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'}};
        assert(canMakeSquare(grid));
    }
    {
        std::vector<std::vector<char>> grid{{'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}};
        assert(!canMakeSquare(grid));
    }
    {
        std::vector<std::vector<char>> grid{{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'W'}};
        assert(canMakeSquare(grid));
    }
    return 0;
}
