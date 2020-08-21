#include <cassert>
#include <vector>

int smallestCommonElement(const std::vector<std::vector<int>> &mat) {
    if (mat.size() == 1) {
        return mat[0][0];
    }

    const auto &firstRow = mat[0];
    for (auto v : firstRow) {
        size_t found = 0;
        for (size_t i = 1; i < mat.size(); ++i) {
            for (auto j : mat[i]) {
                if (v == j) {
                    ++found;
                    break;
                }
                if (v < j) {
                    break;
                }
            }
        }

        if (found == mat.size() - 1) {
            return v;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2, 3, 4, 5},
            {2, 4, 5, 8, 10},
            {3, 5, 7, 9, 11},
            {1, 3, 5, 7, 9},
        };
        assert(smallestCommonElement(input) == 5);
    }
    return 0;
}
