#include <cassert>
#include <vector>
#include <functional>
#include <queue>
#include <map>
#include <set>

std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return std::vector<std::vector<int>>{};
    }
    int cols = matrix[0].size();
    if (cols == 0) {
        return std::vector<std::vector<int>>{};
    }

    std::function<void(std::queue<std::pair<int, int>> & q, std::vector<std::vector<bool>> & visited)> f;
    f = [&matrix, &rows, &cols](std::queue<std::pair<int, int>> &q, std::vector<std::vector<bool>> &visited) {
        const int step_x[] = {0, 1, 0, -1};
        const int step_y[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            visited[row][col] = true;

            for (int i = 0; i < 4; ++i) {
                int next_row = row + step_x[i];
                int next_col = col + step_y[i];

                if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols) {
                    if (matrix[row][col] <= matrix[next_row][next_col] && !visited[next_row][next_col]) {
                        q.push({next_row, next_col});
                    }
                }
            }
        }
    };

    std::vector<std::vector<bool>> visited_pacific(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<bool>> visited_atlantic(rows, std::vector<bool>(cols, false));

    std::queue<std::pair<int, int>> pacific;
    std::queue<std::pair<int, int>> atlantic;

    for (int i = 0; i < rows; ++i) {
        pacific.push({i, 0});
        atlantic.push({i, cols - 1});
    }
    for (int i = 0; i < cols; ++i) {
        pacific.push({0, i});
        atlantic.push({rows - 1, i});
    }

    f(pacific, visited_pacific);
    f(atlantic, visited_atlantic);

    std::vector<std::vector<int>> ret;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (visited_pacific[i][j] && visited_atlantic[i][j]) {
                ret.push_back({i, j});
            }
        }
    }

    return ret;
}

bool check(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
    if (a.size() != b.size()) {
        return false;
    }

    std::set<std::vector<int>> sa, sb;
    for (size_t i = 0; i < a.size(); ++i) {
        sa.insert(a[i]);
        sb.insert(b[i]);
    }

    return sa == sb;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4},
        };
        std::vector<std::vector<int>> expected{
            {0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0},
        };
        auto ret = pacificAtlantic(matrix);
        assert(check(ret, expected));
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5},
        };
        std::vector<std::vector<int>> expected{
            {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2},
        };
        auto ret = pacificAtlantic(matrix);
        assert(check(ret, expected));
    }
    return 0;
}
