#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

int shortestPath(const std::vector<std::vector<int>> &grid, int k) {
    struct Data {
        int row;
        int col;
        int k;
        int count;

        bool operator<(const Data &other) const {
            return std::tuple<int, int, int>(row, col, k) < std::tuple<int, int, int>(other.row, other.col, other.k);
        }
    };

    int rows = grid.size();
    int cols = grid[0].size();

    std::set<Data> checked;
    std::vector<std::vector<int>> steps{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    std::queue<Data> queue;
    queue.push({0, 0, k, 0});

    while (!queue.empty()) {
        auto pos = queue.front();
        queue.pop();

        if (pos.row == rows - 1 && pos.col == cols - 1) {
            return pos.count;
        }

        for (const auto &step : steps) {
            int new_row = pos.row + step[0];
            int new_col = pos.col + step[1];
            if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) {
                continue;
            }

            int eliminations = pos.k - grid[new_row][new_col];
            Data key{new_row, new_col, eliminations, pos.count + 1};
            if (eliminations >= 0 && checked.find(key) == checked.end()) {
                queue.push(key);
                checked.insert(key);
            }
        }
    }

    return -1;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0},
        };
        assert(shortestPath(grid, 1) == 6);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 1, 1},
            {1, 1, 0},
            {1, 0, 0},
        };
        assert(shortestPath(grid, 1) == -1);
    }
    return 0;
}