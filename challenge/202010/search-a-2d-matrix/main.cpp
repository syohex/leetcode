#include <cassert>
#include <vector>
#include <cstdio>

bool searchMatric(const std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }

    size_t row = 0;
    if (matrix.size() > 1) {
        bool found = false;
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (target >= matrix[i].front() && target <= matrix[i].back()) {
                found = true;
                row = i;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    size_t size = matrix[row].size();
    if (size == 1) {
        return target == matrix[row][0];
    }

    int left = 0;
    int right = static_cast<int>(size - 1);
    while (left < right) {
        if (matrix[row][left] == target || matrix[row][right] == target) {
            return true;
        }

        int mid = (left + right) / 2;
        if (matrix[row][mid] == target) {
            return true;
        }

        if (matrix[row][mid] < target) {
            left = mid + 1;
            continue;
        }

        right = mid - 1;
        continue;
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<int>> m{
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50},
        };
        assert(searchMatric(m, 3));
    }
    {
        std::vector<std::vector<int>> m{
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50},
        };
        assert(!searchMatric(m, 13));
    }
    {
        std::vector<std::vector<int>> m{};
        assert(!searchMatric(m, 0));
    }
    {
        std::vector<std::vector<int>> m{
            {1, 1},
        };
        assert(!searchMatric(m, 2));
    }
    {
        std::vector<std::vector<int>> m{
            {1},
        };
        assert(searchMatric(m, 1));
    }
    {
        std::vector<std::vector<int>> m{
            {1},
            {3},
        };
        assert(searchMatric(m, 3));
    }
    return 0;
}
