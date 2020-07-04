#include <cassert>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ret;
    if (numRows == 0) {
        return ret;
    }

    ret.resize(numRows);
    ret[0].push_back(1);

    if (numRows == 1) {
        return ret;
    }

    for (int i = 1; i < numRows; ++i) {
        ret[i].resize(i + 1);
        ret[i][0] = 1;
        ret[i][i] = 1;

        int limit = i + 1 - 2;
        for (int j = 0; j < limit; ++j) {
            ret[i][j + 1] = ret[i - 1][j] + ret[i - 1][j + 1];
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> expected{
            {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1},
        };

        auto ret = generate(5);
        assert(ret == expected);
    }
    return 0;
}
