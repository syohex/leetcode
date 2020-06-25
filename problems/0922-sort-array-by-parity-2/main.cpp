#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> sortArrayByParityII(const std::vector<int> &A) {
    std::vector<int> ret(A.size());
    size_t odd_index = 1, even_index = 0;

    for (size_t i = 0; i < A.size(); ++i) {
        if ((A[i] & 1) == 1) {
            ret[odd_index] = A[i];
            odd_index += 2;
        } else {
            ret[even_index] = A[i];
            even_index += 2;
        }
    }

    return ret;
}

bool check(const std::vector<int> &got) {
    printf("[");
    for (size_t i = 0; i < got.size(); i += 2) {
        assert(got[i] % 2 == 0);
        assert(got[i + 1] % 2 == 1);

        printf(" %d %d", got[i], got[i + 1]);
    }
    printf("]\n");

    return true;
}

int main() {
    {
        std::vector<int> input{4, 2, 5, 7};
        auto ret = sortArrayByParityII(input);
        assert(check(ret));
    }
    {
        std::vector<int> input{3, 4};
        auto ret = sortArrayByParityII(input);
        assert(check(ret));
    }
    return 0;
}
