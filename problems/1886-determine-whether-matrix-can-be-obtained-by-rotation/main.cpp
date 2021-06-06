#include <cassert>
#include <vector>

bool findRotation(std::vector<std::vector<int>> &mat, const std::vector<std::vector<int>> &target) {
    const auto rotate90 = [](std::vector<std::vector<int>> &m) {
        auto tmp = m;
        for (size_t i = 0; i < m.size(); ++i) {
            for (size_t j = 0; j < m[i].size(); ++j) {
                tmp[j][i] = m[i][j];
            }
        }

        auto tmp2 = tmp;
        for (size_t i = 0; i < m.size(); ++i) {
            size_t cols = m[i].size();
            for (size_t j = 0; j < cols; ++j) {
                tmp2[i][j] = tmp[i][cols - 1 - j];
            }
        }

        m = tmp2;
    };

    if (mat == target) {
        return true;
    }

    for (int i = 0; i < 3; ++i) {
        rotate90(mat);
        if (mat == target) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<int>> mat{
            {0, 1},
            {1, 0},
        };
        std::vector<std::vector<int>> target{
            {1, 0},
            {0, 1},
        };
        assert(findRotation(mat, target));
    }
    {
        std::vector<std::vector<int>> mat{
            {0, 1},
            {1, 1},
        };
        std::vector<std::vector<int>> target{
            {1, 0},
            {0, 1},
        };
        assert(!findRotation(mat, target));
    }
    {
        std::vector<std::vector<int>> mat{
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1},
        };
        std::vector<std::vector<int>> target{
            {1, 1, 1},
            {0, 1, 0},
            {0, 0, 0},
        };
        assert(findRotation(mat, target));
    }
    return 0;
}