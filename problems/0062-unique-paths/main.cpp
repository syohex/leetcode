#include <cassert>
#include <vector>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> table(m);
    for (int i = 0; i < m; ++i) {
        table[i] = std::vector<int>(n, 0);
    }

    table[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >= 1) {
                table[i][j] += table[i][j - 1];
            }
            if (i >= 1) {
                table[i][j] += table[i - 1][j];
            }
        }
    }

    return table.back().back();
}

int main() {
    assert(uniquePaths(3, 7) == 28);
    assert(uniquePaths(3, 2) == 3);
    assert(uniquePaths(7, 3) == 28);
    assert(uniquePaths(3, 3) == 6);
    return 0;
}
