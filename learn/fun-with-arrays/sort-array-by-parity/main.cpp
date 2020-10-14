#include <cassert>
#include <vector>

std::vector<int> sortArrayByParity(std::vector<int> &A) {
    if (A.size() <= 1) {
        return A;
    }

    size_t replace_pos = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] % 2 == 0) {
            int tmp = A[replace_pos];
            A[replace_pos++] = A[i];
            A[i] = tmp;
        }
    }
    return A;
}

int main() {
    {
        std::vector<int> input{3, 1, 2, 4};
        auto ret = sortArrayByParity(input);
        assert(ret == input);
        assert((ret == std::vector<int>{2, 4, 3, 1}));
    }
    {
        std::vector<int> input{3, 2, 4};
        auto ret = sortArrayByParity(input);
        assert(ret == input);
        assert((ret == std::vector<int>{2, 4, 3}));
    }
    return 0;
}
