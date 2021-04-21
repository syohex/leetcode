#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int minimumTotal(const std::vector<std::vector<int>> &triangle) {
    std::vector<std::vector<int>> distances;
    for (size_t i = 0; i < triangle.size(); ++i) {
        distances.push_back(std::vector<int>(triangle[i].size(), 0));
    }

    distances[0][0] = triangle[0][0];
    for (size_t i = 1; i < triangle.size(); ++i) {
        for (size_t j = 0; j < triangle[i].size(); ++j) {
            if (j == 0) {
                distances[i][j] = triangle[i][j] + distances[i - 1][0];
            } else if (j == triangle[i].size() - 1) {
                distances[i][j] = triangle[i][j] + distances[i - 1].back();
            } else {
                int min = std::min(distances[i - 1][j - 1], distances[i - 1][j]);
                distances[i][j] = triangle[i][j] + min;
            }
        }
    }

    int ret = INT_MAX;
    for (int d : distances.back()) {
        ret = std::min(ret, d);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> triangle{
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3},
        };

        assert(minimumTotal(triangle) == 11);
    }
    {
        std::vector<std::vector<int>> triangle{
            {-10},
        };

        assert(minimumTotal(triangle) == -10);
    }
    return 0;
}
