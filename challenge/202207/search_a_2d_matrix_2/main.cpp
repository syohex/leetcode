#include <cassert>
#include <vector>
#include <algorithm>

bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target) {
    int rows = matrix.size();
    for (int i = rows - 1; i >= 0; --i) {
        const auto &v = matrix[i];
        if (v[0] > target) {
            continue;
        }

        if (std::binary_search(v.begin(), v.end(), target)) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30},
        };
        assert(searchMatrix(matrix, 5));
    }
    {
        std::vector<std::vector<int>> matrix{
            {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30},
        };
        assert(!searchMatrix(matrix, 20));
    }
    return 0;
}
