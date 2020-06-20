#include <cassert>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &A) {
    std::vector<std::vector<int>> ret;
    ret.resize(A[0].size());

    for (size_t i = 0; i < A[0].size(); ++i) {
        ret[i].resize(A.size());
    }

    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[0].size(); ++j) {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        std::vector<std::vector<int>> expected{
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
        };

        auto ret = transpose(input);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 2, 3},
            {4, 5, 6},
        };
        std::vector<std::vector<int>> expected{
            {1, 4},
            {2, 5},
            {3, 6},
        };

        auto ret = transpose(input);
        assert(ret == expected);
    }
    return 0;
}
