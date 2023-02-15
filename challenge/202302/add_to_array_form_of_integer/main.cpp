#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> addToArrayForm(std::vector<int> &num, int k) {
    std::reverse(num.begin(), num.end());

    std::vector<int> ks;
    while (k != 0) {
        ks.push_back(k % 10);
        k /= 10;
    }

    int n_len = num.size();
    int k_len = ks.size();

    std::vector<int> ret;
    int carry = 0;
    for (int i = 0, j = 0; i < n_len || j < k_len; ++i, ++j) {
        int v1 = i < n_len ? num[i] : 0;
        int v2 = j < k_len ? ks[j] : 0;

        int v = v1 + v2 + carry;
        if (v >= 10) {
            ret.push_back(v - 10);
            carry = 1;
        } else {
            ret.push_back(v);
            carry = 0;
        }
    }

    if (carry == 1) {
        ret.push_back(1);
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    {
        std::vector<int> num{1, 2, 0, 0};
        int k = 34;
        std::vector<int> expected{1, 2, 3, 4};
        auto ret = addToArrayForm(num, k);
        assert(ret == expected);
    }
    {
        std::vector<int> num{2, 7, 4};
        int k = 181;
        std::vector<int> expected{4, 5, 5};
        auto ret = addToArrayForm(num, k);
        assert(ret == expected);
    }
    {
        std::vector<int> num{2, 1, 5};
        int k = 806;
        std::vector<int> expected{1, 0, 2, 1};
        auto ret = addToArrayForm(num, k);
        assert(ret == expected);
    }
    {
        std::vector<int> num{0};
        int k = 0;
        std::vector<int> expected{0};
        auto ret = addToArrayForm(num, k);
        assert(ret == expected);
    }
    return 0;
}
