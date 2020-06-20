#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

std::vector<int> kWeakestRows(const std::vector<std::vector<int>> &mat, int k) {
    std::vector<std::pair<int, int>> tmp;
    for (size_t i = 0; i < mat.size(); ++i) {
        int nums = 0;
        for (const auto n : mat[i]) {
            if (n == 1) {
                ++nums;
            }
        }

        tmp.push_back(std::make_pair(i, nums));
    }

    std::sort(tmp.begin(), tmp.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.second != b.second) {
            // compare soldiers
            return a.second <= b.second;
        }

        // compare index
        return a.first <= b.first;
    });

    printf("[");
    for (const auto &p : tmp) {
        printf(" [ %d %d ] ", p.first, p.second);
    }
    printf("]\n");

    std::vector<int> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(tmp[i].first);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1},
        };
        auto ret = kWeakestRows(input, 3);
        assert((ret == std::vector<int>{2, 0, 3}));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
        };
        auto ret = kWeakestRows(input, 2);
        assert((ret == std::vector<int>{0, 2}));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
        };
        auto ret = kWeakestRows(input, 1);
        assert((ret == std::vector<int>{0}));
    }

    return 0;
}
