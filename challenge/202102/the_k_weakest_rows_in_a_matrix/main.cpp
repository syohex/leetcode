#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> kWeakestRows(const std::vector<std::vector<int>> &mat, int k) {
    struct Data {
        int index;
        int soldiers;
    };

    std::vector<Data> v;
    for (size_t i = 0; i < mat.size(); ++i) {
        int count = 0;
        for (int n : mat[i]) {
            if (n == 1) {
                ++count;
            }
        }

        v.emplace_back(Data{static_cast<int>(i), count});
    }

    std::sort(v.begin(), v.end(), [](const Data &a, const Data &b) -> bool {
        if (a.soldiers == b.soldiers) {
            return a.index < b.index;
        }

        return a.soldiers < b.soldiers;
    });

    std::vector<int> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(v[i].index);
    }

    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> mat {
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 1},
        };
        // clang-format on

        auto ret = kWeakestRows(mat, 3);
        assert((ret == std::vector<int>{2, 0, 3}));
    }
    {
        // clang-format off
        std::vector<std::vector<int>> mat {
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
        };
        // clang-format on

        auto ret = kWeakestRows(mat, 2);
        assert((ret == std::vector<int>{0, 2}));
    }
    return 0;
}
