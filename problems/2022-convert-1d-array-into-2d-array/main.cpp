#include <cassert>
#include <vector>

std::vector<std::vector<int>> construct2DArray(const std::vector<int> &original, int m, int n) {
    int len = original.size();
    if (m * n != len) {
        return {};
    }

    std::vector<std::vector<int>> ret(m, std::vector<int>(n));
    int p = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i][j] = original[p++];
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> original{1, 2, 3, 4};
        std::vector<std::vector<int>> expected{{1, 2}, {3, 4}};
        auto ret = construct2DArray(original, 2, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> original{1, 2, 3};
        std::vector<std::vector<int>> expected{{1, 2, 3}};
        auto ret = construct2DArray(original, 1, 3);
        assert(ret == expected);
    }
    {
        std::vector<int> original{1, 2};
        auto ret = construct2DArray(original, 1, 1);
        assert(ret.empty());
    }
    {
        std::vector<int> original{3};
        auto ret = construct2DArray(original, 1, 2);
        assert(ret.empty());
    }
    return 0;
}
