#include <cassert>
#include <vector>
#include <utility>
#include <functional>

void solve(std::vector<std::vector<char>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    std::function<void(int row, int col)> f;
    f = [&](int row, int col) {
        if (board[row][col] != 'O') {
            return;
        }

        board[row][col] = '#';
        if (row >= 1) {
            f(row - 1, col);
        }
        if (col >= 1) {
            f(row, col - 1);
        }
        if (row < rows - 1) {
            f(row + 1, col);
        }
        if (col < cols - 1) {
            f(row, col + 1);
        }
    };

    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < rows; ++i) {
        points.push_back({i, 0});
        points.push_back({i, cols - 1});
    }
    for (int i = 0; i < cols; ++i) {
        points.push_back({0, i});
        points.push_back({rows - 1, i});
    }

    for (const auto &point : points) {
        f(point.first, point.second);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<char>> board{
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
        };
        std::vector<std::vector<char>> expected{
            {'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X'}
        };
        // clang-format on
        solve(board);
        assert(board == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<char>> board{
            {'X'},
        };
        std::vector<std::vector<char>> expected{
            {'X'},
        };
        // clang-format on
        solve(board);
        assert(board == expected);
    }
    return 0;
}