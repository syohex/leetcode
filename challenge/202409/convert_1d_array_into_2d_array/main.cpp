#include <cassert>
#include <vector>

std::vector<std::vector<int>> construct2DArray(const std::vector<int> &original, int m, int n) {
    int len = original.size();
    if (len != m * n) {
        return {};
    }

    std::vector<std::vector<int>> ret(m, std::vector<int>(n, 0));
    for (int i = 0; i < len; ++i) {
        int row = i / n;
        int col = i % n;
        ret[row][col] = original[i];
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
    return 0;
}
