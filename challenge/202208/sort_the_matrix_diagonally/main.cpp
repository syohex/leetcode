#include <cassert>
#include <vector>
#include <map>
#include <queue>

std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>> &mat) {
    std::map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> m;

    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int key = i - j;
            m[key].push(mat[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int key = i - j;
            mat[i][j] = m[key].top();
            m[key].pop();
        }
    }

    return mat;
}

int main() {
    {
        std::vector<std::vector<int>> mat{
            {3, 3, 1, 1},
            {2, 2, 1, 2},
            {1, 1, 1, 2},
        };
        std::vector<std::vector<int>> expected{
            {1, 1, 1, 1},
            {1, 2, 2, 2},
            {1, 2, 3, 3},
        };

        auto ret = diagonalSort(mat);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> mat{
            {11, 25, 66, 1, 69, 7},  {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8},
            {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50},
        };
        std::vector<std::vector<int>> expected{
            {5, 17, 4, 1, 52, 7},     {11, 11, 25, 45, 8, 69},  {14, 23, 25, 44, 58, 15},
            {22, 27, 31, 36, 50, 66}, {84, 28, 75, 33, 55, 68},
        };

        auto ret = diagonalSort(mat);
        assert(ret == expected);
    }

    return 0;
}
