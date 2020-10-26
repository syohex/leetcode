#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>

double champagneTower(int poured, int query_row, int query_glass) {
    // 100th(zero-based) row and extra row
    double glasses[102][102];
    memset(&glasses, 0, 102 * 102 * sizeof(double));

    glasses[0][0] = poured;
    for (int i = 0; i <= query_row; ++i) {
        for (int j = 0; j <= query_glass; ++j) {
            double v = (glasses[i][j] - 1.0) / 2;
            if (v > 0) {
                glasses[i + 1][j] += v;
                glasses[i + 1][j + 1] += v;
            }
        }
    }

    return std::min(1.0, glasses[query_row][query_glass]);
}

int main() {
    assert(champagneTower(1, 1, 1) == 0);
    assert(champagneTower(2, 1, 1) == 0.5);
    assert(champagneTower(100000009, 33, 17) == 1.0);
    return 0;
}
