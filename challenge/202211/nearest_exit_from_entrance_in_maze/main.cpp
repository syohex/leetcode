#include <cassert>
#include <vector>
#include <functional>
#include <set>
#include <numeric>
#include <algorithm>

int nearestExit(const std::vector<std::vector<char>> &maze, const std::vector<int> &entrance) {
    int rows = maze.size();
    int cols = maze[0].size();
    std::vector<std::vector<int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    std::function<int(int row, int col, int n, std::set<std::vector<int>> &visited)> f;
    f = [&](int row, int col, int n, std::set<std::vector<int>> &visited) -> int {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return n - 1;
        }

        int ret = std::numeric_limits<int>::max();
        for (const auto &step : steps) {
            int new_row = row + step[0];
            int new_col = col + step[1];

            std::vector<int> key{new_row, new_col};
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
                if (maze[new_row][new_col] == '+') {
                    continue;
                }

                if (visited.find(key) != visited.end()) {
                    continue;
                }
            }

            visited.insert(key);
            int r = f(new_row, new_col, n + 1, visited);
            if (r > 0) {
                ret = std::min(ret, r);
            }
            visited.erase(key);
        }

        return ret;
    };

    std::set<std::vector<int>> visited{entrance};
    int ret = f(entrance[0], entrance[1], 0, visited);
    return ret == std::numeric_limits<int>::max() ? -1 : ret;
}

int main() {
    {
        std::vector<std::vector<char>> maze{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
        std::vector<int> entrance{1, 2};
        int ret = nearestExit(maze, entrance);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<char>> maze{{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
        std::vector<int> entrance{1, 0};
        int ret = nearestExit(maze, entrance);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<char>> maze{{'.', '+'}};
        std::vector<int> entrance{0, 0};
        int ret = nearestExit(maze, entrance);
        assert(ret == -1);
    }
    {
        std::vector<std::vector<char>> maze{{'+', '.', '+', '+', '+', '+', '+'},
                                            {'+', '.', '+', '.', '.', '.', '+'},
                                            {'+', '.', '+', '.', '+', '.', '+'},
                                            {'+', '.', '.', '.', '+', '.', '+'},
                                            {'+', '+', '+', '+', '+', '.', '+'}};
        std::vector<int> entrance{0, 1};
        int ret = nearestExit(maze, entrance);
        assert(ret == 12);
    }

    return 0;
}
