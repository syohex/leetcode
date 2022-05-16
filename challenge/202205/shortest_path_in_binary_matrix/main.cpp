#include <cassert>
#include <vector>
#include <queue>

int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid) {
    struct Data {
        int row;
        int col;
        int cost;
    };

    std::deque<Data> q;
    if (grid[0][0] == 0) {
        q.push_back({0, 0, 1});
        grid[0][0] = 1;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::pair<int, int>> steps{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    while (!q.empty()) {
        Data d = q.front();
        q.pop_front();

        if (d.row == rows - 1 && d.col == cols - 1) {
            return d.cost;
        }

        for (const auto &step : steps) {
            int row = d.row + step.first;
            int col = d.col + step.second;

            if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 0) {
                q.push_back({row, col, d.cost + 1});
                grid[row][col] = 1;
            }
        }
    }

    return -1;
}

int main() {
    {
        std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
        assert(shortestPathBinaryMatrix(grid) == 2);
    }
    {
        std::vector<std::vector<int>> grid{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
        assert(shortestPathBinaryMatrix(grid) == 4);
    }
    {
        std::vector<std::vector<int>> grid{{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
        assert(shortestPathBinaryMatrix(grid) == -1);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 1, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1}, {0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 1}, {0, 0, 1, 0, 1, 0},
        };
        assert(shortestPathBinaryMatrix(grid) == 7);
    }
    return 0;
}
