#include <cassert>
#include <vector>

std::vector<int> sortArrayByParityII(const std::vector<int> &A) {
    std::vector<int> odds, evens;
    for (size_t i = 0; i < A.size(); ++i) {
        if ((A[i] & 1) == 1) {
            odds.push_back(A[i]);
        } else {
            evens.push_back(A[i]);
        }
    }

    std::vector<int> ret(A.size());
    for (size_t i = 0, j = 0; i < A.size() / 2; ++i) {
        ret[j++] = odds[i];
        ret[j++] = evens[i];
    }

    printf("[");
    for (const auto i : ret) {
        printf(" %d ", i);
    }
    printf("]\n");

    return ret;
}

bool check(const std::vector<int> &got) {
    if (got.size() <= 1) {
        return true;
    }

    if (got[0] % 2 == 0) {
        for (size_t i = 0; i < got.size(); i += 2) {
            assert(got[2 * i] % 2 == 0);
            assert(got[2 * i + 1] % 2 == 1);
        }
    } else {
        for (size_t i = 0; i < got.size(); i += 2) {
            assert(got[2 * i] % 2 == 1);
            assert(got[2 * i + 1] % 2 == 0);
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> input{4, 2, 5, 7};
        auto ret = sortArrayByParityII(input);
        assert(check(ret));
    }
    return 0;
}
