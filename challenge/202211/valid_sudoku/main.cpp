#include <cassert>
#include <vector>
#include <vector>
#include <cstdio>
#include <set>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::vector<std::set<char>> rows(9);
    std::vector<std::set<char>> cols(9);
    std::vector<std::set<char>> boxes(9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }

            if (rows[i].find(c) != rows[i].end()) {
                return false;
            }
            rows[i].insert(c);

            if (cols[j].find(c) != cols[j].end()) {
                return false;
            }
            cols[j].insert(c);

            int index = (i / 3) * 3 + j / 3;
            if (boxes[index].find(c) != boxes[index].end()) {
                return false;
            }

            boxes[index].insert(c);
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<char>> board{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        assert(isValidSudoku(board));
    }
    {
        std::vector<std::vector<char>> board{
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        assert(!isValidSudoku(board));
    }
    return 0;
}
