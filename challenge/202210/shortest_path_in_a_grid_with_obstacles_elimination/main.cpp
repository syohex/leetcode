#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

int shortestPath(const std::vector<std::vector<int>> &grid, int k) {
    struct Data {
        int row;
        int col;
        int eliminations;
        int steps;

        bool operator<(const Data &o) const {
            return std::tuple<int, int, int>(row, col, eliminations) < std::tuple<int, int, int>(o.row, o.col, o.eliminations);
        }
    };

    int rows = grid.size();
    int cols = grid[0].size();
    const auto cmp = [](const Data &a, const Data &b) -> bool { return a.steps > b.steps; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({0, 0, k, 0});

    std::set<Data> checked;
    checked.insert(q.top());

    const std::vector<std::vector<int>> steps{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        auto d = q.top();
        q.pop();

        if (d.row == rows - 1 && d.col == cols - 1) {
            return d.steps;
        }

        for (const auto &step : steps) {
            int new_row = d.row + step[0];
            int new_col = d.col + step[1];
            if (!(new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols)) {
                continue;
            }

            int new_eliminations = d.eliminations - grid[new_row][new_col];
            if (new_eliminations < 0) {
                continue;
            }

            Data new_d{new_row, new_col, new_eliminations, d.steps + 1};
            if (checked.find(new_d) == checked.end()) {
                q.push(new_d);
                checked.insert(new_d);
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
        auto ret = shortestPath(grid, 1);
        assert(ret == 6);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 1, 1},
            {1, 1, 1},
            {1, 0, 0},
        };
        auto ret = shortestPath(grid, 1);
        assert(ret == -1);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 1},
            {1, 1, 1},
            {1, 1, 0},
        };
        auto ret = shortestPath(grid, 1);
        assert(ret == -1);
    }
    return 0;
}