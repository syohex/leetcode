#include <cassert>
#include <vector>

std::vector<std::vector<int>> flipAndInvertImage(const std::vector<std::vector<int>> &A) {
    std::vector<std::vector<int>> ret(A.size());
    for (size_t i = 0; i < A.size(); ++i) {
        size_t columns = A[i].size();
        ret[i].resize(columns);

        for (size_t j = 0; j < columns; ++j) {
            ret[i][j] = A[i][columns - j - 1] == 1 ? 0 : 1;
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
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{1, 0, 0}));
        assert((ret[1] == std::vector<int>{0, 1, 0}));
        assert((ret[2] == std::vector<int>{1, 1, 1}));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1, 0, 0},
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {1, 0, 1, 0},
        };
        auto ret = flipAndInvertImage(input);
        assert(ret.size() == 4);
        assert((ret[0] == std::vector<int>{1, 1, 0, 0}));
        assert((ret[1] == std::vector<int>{0, 1, 1, 0}));
        assert((ret[2] == std::vector<int>{0, 0, 0, 1}));
        assert((ret[3] == std::vector<int>{1, 0, 1, 0}));
    }
    return 0;
}
