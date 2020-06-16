#include <cassert>
#include <vector>

std::vector<int> sortArrayByParity(const std::vector<int> &A) {
    std::vector<int> ret(A.size(), 0);
    size_t evenPos = 0, oddPos = A.size() - 1;

    for (const auto i : A) {
        if ((i & 0x1) == 0) {
            ret[evenPos++] = i;
        } else {
            ret[oddPos--] = i;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{2, 4, 6, 8};
        auto ret = sortArrayByParity(input);
        assert(input == ret);
    }
    {
        std::vector<int> input{3, 1, 2, 4};
        auto ret = sortArrayByParity(input);

        std::vector<int> expected{2, 4, 1, 3};
        assert(ret == expected);
    }
    return 0;
}
