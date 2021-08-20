#include <cassert>
#include <vector>
#include <functional>
#include <set>

bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    std::vector<std::set<int>> horizontals(9);
    std::vector<std::set<int>> verticals(9);
    std::vector<std::set<int>> blocks(9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int v1 = board[i][j];
            if (v1 != '.') {
                if (horizontals[i].find(v1) != horizontals[i].end()) {
                    return false;
                }

                horizontals[i].insert(v1);
            }

            int v2 = board[j][i];
            if (v2 != '.') {
                if (verticals[i].find(v2) != verticals[i].end()) {
                    return false;
                }

                verticals[i].insert(board[j][i]);
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        int row_base = 3 * (i / 3);
        int col_base = 3 * (i % 3);
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                int v = board[row_base + j][col_base + k];
                if (v != '.') {
                    if (blocks[i].find(v) != blocks[i].end()) {
                        return false;
                    }

                    blocks[i].insert(v);
                }
            }
        }
    }

    return true;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<char>> board{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
		};
        // clang-format on
        assert(isValidSudoku(board));
    }
    {
        // clang-format off
        std::vector<std::vector<char>> board{
			{'8','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'},
		};
        // clang-format on
        assert(!isValidSudoku(board));
    }

    return 0;
}
