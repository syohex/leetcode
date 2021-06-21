#include <cassert>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ret;
    ret.push_back(std::vector<int>{1});

    for (int i = 1; i < numRows; ++i) {
        std::vector<int> v;
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                v.push_back(ret[i - 1][0]);
            } else if (j == i) {
                v.push_back(ret[i - 1][j - 1]);
            } else {
                v.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            }
        }
        ret.push_back(v);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> expected{
            {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1},
        };
        auto got = generate(5);
        assert(got == expected);
    }
    {
        std::vector<std::vector<int>> expected{
            {1},
        };
        auto got = generate(1);
        assert(got == expected);
    }
    return 0;
}
