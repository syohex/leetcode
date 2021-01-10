#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> decode(const std::vector<int> &encoded, int first) {
    std::vector<int> ret{first};
    int num = first;
    for (int e : encoded) {
        ret.push_back(num ^ e);
        num = ret.back();
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2, 3};
        std::vector<int> expected{1, 0, 2, 1};
        auto ret = decode(input, 1);
        assert(ret == expected);
    }
    {
        std::vector<int> input{6, 2, 7, 3};
        std::vector<int> expected{4, 2, 0, 7, 4};
        auto ret = decode(input, 4);
        assert(ret == expected);
    }
    return 0;
}
