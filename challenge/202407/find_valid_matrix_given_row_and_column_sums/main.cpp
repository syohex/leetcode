#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> restoreMatrix(const std::vector<int> &rowSum, const std::vector<int> &colSum) {
    int rows = rowSum.size();
    int cols = colSum.size();

    std::vector<std::vector<int>> ret(rows, std::vector<int>(cols, 0));

    std::vector<int> r(rows, 0);
    std::vector<int> c(cols, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ret[i][j] = std::min(rowSum[i] - r[i], colSum[j] - c[j]);

            r[i] += ret[i][j];
            c[j] += ret[i][j];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> rowSum{3, 8};
        std::vector<int> colSum{4, 7};
        std::vector<std::vector<int>> expected{{3, 0}, {1, 7}};
        auto ret = restoreMatrix(rowSum, colSum);
        assert(ret == expected);
    }
    {
        std::vector<int> rowSum{5, 7, 10};
        std::vector<int> colSum{8, 6, 8};
        std::vector<std::vector<int>> expected{{5, 0, 0}, {3, 4, 0}, {0, 2, 8}};
        auto ret = restoreMatrix(rowSum, colSum);
        assert(ret == expected);
    }
    return 0;
}
