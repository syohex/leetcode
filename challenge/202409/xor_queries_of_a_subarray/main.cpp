#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> xorQueries(const std::vector<int> &arr, const std::vector<std::vector<int>> &queries) {
    std::vector<int> acc(arr.size() + 1, 0);
    for (std::size_t i = 0; i < arr.size(); ++i) {
        acc[i + 1] = acc[i] ^ arr[i];
    }

    std::vector<int> ret;
    for (const auto &q : queries) {
        ret.push_back(acc[q[1] + 1] ^ acc[q[0]]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> arr{1, 3, 4, 8};
        std::vector<std::vector<int>> queries{{0, 1}, {1, 2}, {0, 3}, {3, 3}};
        std::vector<int> expected{2, 7, 14, 8};

        auto ret = xorQueries(arr, queries);
        assert(ret == expected);
    }
    {
        std::vector<int> arr{4, 8, 2, 10};
        std::vector<std::vector<int>> queries{{2, 3}, {1, 3}, {0, 0}, {0, 3}};
        std::vector<int> expected{8, 0, 4, 4};

        auto ret = xorQueries(arr, queries);
        assert(ret == expected);
    }
    return 0;
}