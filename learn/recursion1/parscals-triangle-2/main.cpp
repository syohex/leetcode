#include <cassert>
#include <vector>
#include <functional>

std::vector<int> getRow(int rowIndex) {
    std::function<int(int row, int col, int max_col)> f;
    f = [&f](int row, int col, int max_col) -> int {
        if (row == 0 || col == 0 || col == max_col) {
            return 1;
        }

        return f(row - 1, col - 1, max_col - 1) + f(row - 1, col, max_col - 1);
    };

    std::vector<int> ret;
    for (int i = 0; i <= rowIndex; ++i) {
        ret.push_back(f(rowIndex, i, rowIndex));
    }

    return ret;
}

int main() {
    assert((getRow(3) == std::vector<int>{1, 3, 3, 1}));
    assert((getRow(0) == std::vector<int>{1}));
    assert((getRow(1) == std::vector<int>{1, 1}));
    return 0;
}
