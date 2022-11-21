#include <cassert>
#include <vector>
#include <set>
#include <queue>

int nearestExit(const std::vector<std::vector<char>> &maze, const std::vector<int> &entrance) {
    int rows = maze.size();
    int cols = maze[0].size();
    std::vector<std::vector<int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    struct Data {
        int row;
        int col;
        int step;
    };
    const auto cmp = [](const Data &a, const Data &b) -> bool { return a.step > b.step; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({entrance[0], entrance[1], 0});

    std::set<std::vector<int>> visited{entrance};
    while (!q.empty()) {
        Data d = q.top();
        q.pop();

        if (d.row < 0 || d.row >= rows || d.col < 0 || d.col >= cols) {
            if (d.step == 1) {
                // entrance is exit
                continue;
            }

            return d.step - 1;
        }

        for (const auto &step : steps) {
            int new_row = d.row + step[0];
            int new_col = d.col + step[1];

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
            q.push({new_row, new_col, d.step + 1});
        }
    }

    return -1;
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
