#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>> &score, int k) {
    std::sort(score.begin(), score.end(), [&](const auto& a, const auto& b) {
        return a[k] > b[k];
    });

    return score;
}

int main() {
    {
        std::vector<std::vector<int>> score{{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}};
        std::vector<std::vector<int>> expected{{7, 5, 11, 2}, {10, 6, 9, 1}, {4, 8, 3, 15}};
        auto ret = sortTheStudents(score, 2);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> score{{3, 4}, {5, 6}};
        std::vector<std::vector<int>> expected{{5, 6}, {3, 4}};
        auto ret = sortTheStudents(score, 0);
        assert(ret == expected);
    }
    return 0;
}
