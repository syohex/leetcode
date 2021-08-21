#include <cassert>
#include <vector>
#include <functional>

void solveSudoku(std::vector<std::vector<char>> &board) {
    const auto valid = [&board](int x, int y, int val) -> bool {
        for (int i = 0; i < 9; ++i) {
            if (board[x][i] == val) {
                return false;
            }
            if (board[i][y] == val) {
                return false;
            }
        }

        int x_base = (x / 3) * 3;
        int y_base = (y / 3) * 3;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[x_base + i][y_base + j] == val) {
                    return false;
                }
            }
        }

        return true;
    };

    std::function<bool(int x, int y)> f;
    f = [&f, &valid, &board](int x, int y) -> bool {
        if (x == 9) {
            return true;
        }
        if (y == 9) {
            return f(x + 1, 0);
        }

        if (board[x][y] != '.') {
            return f(x, y + 1);
        }

        for (int i = 1; i <= 9; ++i) {
            int v = i + '0';
            if (valid(x, y, v)) {
                board[x][y] = v;
                if (f(x, y + 1)) {
                    return true;
                }
                board[x][y] = '.';
            }
        }

        return false;
    };

    (void)f(0, 0);
}

int main() {
    {
        std::vector<std::vector<char>> board{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
        };

        std::vector<std::vector<char>> expected{
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'}, {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'}, {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'}, {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'}, {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'},
        };

        solveSudoku(board);
        assert(board == expected);
    }
    return 0;
}