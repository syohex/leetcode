#include <cassert>
#include <vector>
#include <queue>
#include <set>

int shortestPathBinaryMatrix(const std::vector<std::vector<int>> &grid) {
    if (grid[0][0] == 1) {
        return -1;
    }

    struct Data {
        int row;
        int col;
        int cost;
    };

    const auto cmp = [](const Data &a, const Data &b) { return a.cost > b.cost; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({0, 0, 1});

    int rows = grid.size();
    int cols = grid[0].size();

    std::set<std::pair<int, int>> visited;

    std::vector<std::pair<int, int>> steps{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    while (!q.empty()) {
        Data d = q.top();
        q.pop();

        visited.insert({d.row, d.col});

        if (d.row == rows - 1 && d.col == cols - 1) {
            return d.cost;
        }

        for (const auto &step : steps) {
            int row = d.row + step.first;
            int col = d.col + step.second;

            if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 0) {
                if (visited.find({row, col}) == visited.end()) {
                    q.push({row, col, d.cost + 1});
                }
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
