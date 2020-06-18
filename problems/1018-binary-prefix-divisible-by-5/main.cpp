#include <cassert>
#include <vector>

std::vector<bool> prefixesDivBy5(const std::vector<int> &A) {
    std::vector<bool> ret(A.size(), false);
    int num = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        num += A[i];
        int mod = num % 5;
        ret[i] = mod == 0;
        num = mod << 1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{0, 1, 1};
        auto ret = prefixesDivBy5(input);
        assert((ret == std::vector<bool>{true, false, false}));
    }
    {
        std::vector<int> input{1, 1, 1};
        auto ret = prefixesDivBy5(input);
        assert((ret == std::vector<bool>{false, false, false}));
    }
    {
        std::vector<int> input{0, 1, 1, 1, 1, 1};
        auto ret = prefixesDivBy5(input);
        assert((ret == std::vector<bool>{true, false, false, false, true, false}));
    }
    {
        std::vector<int> input{1, 1, 1, 0, 1};
        auto ret = prefixesDivBy5(input);
        assert((ret == std::vector<bool>{false, false, false, false, false}));
    }
    return 0;
}
