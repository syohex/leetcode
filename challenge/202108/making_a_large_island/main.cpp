#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

int largestIsland(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::pair<int, int>> steps{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    const auto f = [&grid, &rows, &cols, &steps](int row, int col) -> int {
        int index = row * rows + col;
        std::stack<int> stack;
        stack.push(index);

        std::set<int> checked;
        checked.insert(index);

        while (!stack.empty()) {
            auto i = stack.top();
            stack.pop();

            int base_x = i / rows;
            int base_y = i % rows;
            for (const auto &step : steps) {
                int x = base_x + step.first;
                int y = base_y + step.second;

                int new_index = x * rows + y;
                if (checked.find(new_index) != checked.end()) {
                    continue;
                }

                if (!(x >= 0 && x < rows && y >= 0 && y < cols)) {
                    continue;
                }

                if (grid[x][y] == 0) {
                    continue;
                }

                stack.push(new_index);
                checked.insert(new_index);
            }
        }

        return checked.size();
    };

    int ret = -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                grid[i][j] = 1;
                ret = std::max(ret, f(i, j));
                grid[i][j] = 0;
            }
        }
    }

    return ret == -1 ? rows * cols : ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{{1, 0}, {0, 1}};
        assert(largestIsland(grid) == 3);
    }
    {
        std::vector<std::vector<int>> grid{{1, 1}, {1, 0}};
        assert(largestIsland(grid) == 4);
    }
    {
        std::vector<std::vector<int>> grid{{1, 1}, {1, 1}};
        assert(largestIsland(grid) == 4);
    }
    return 0;
}