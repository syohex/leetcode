#include <cassert>
#include <vector>

std::vector<std::vector<int>> flipAndInvertImage(const std::vector<std::vector<int>> &A) {
    std::vector<std::vector<int>> ret(A.size());

    for (int i = 0; i < static_cast<int>(A.size()); ++i) {
        for (int j = static_cast<int>(A[0].size() - 1); j >= 0; --j) {
            ret[i].push_back(A[i][j] == 1 ? 0 : 1);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0},
        };
        auto ret = flipAndInvertImage(input);

        std::vector<std::vector<int>> expected{
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1},
        };

        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1, 0, 0},
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {1, 0, 1, 0},
        };
        auto ret = flipAndInvertImage(input);

        std::vector<std::vector<int>> expected{
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 0},
        };

        assert(ret == expected);
    }
    return 0;
}
