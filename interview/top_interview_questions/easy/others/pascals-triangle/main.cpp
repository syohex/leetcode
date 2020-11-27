#include <cassert>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ret;
    if (numRows == 0) {
        return ret;
    }

    for (int i = 0; i < numRows; ++i) {
        ret.emplace_back(std::vector<int>{});
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                ret[i].push_back(1);
            } else {
                ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            }
        }
    }

    return ret;
}

int main() {
    {
        auto ret = generate(5);
        assert(ret.size() == 5);
        assert((ret[0] == std::vector<int>{1}));
        assert((ret[1] == std::vector<int>{1, 1}));
        assert((ret[2] == std::vector<int>{1, 2, 1}));
        assert((ret[3] == std::vector<int>{1, 3, 3, 1}));
        assert((ret[4] == std::vector<int>{1, 4, 6, 4, 1}));
    }
    return 0;
}
