#include <cassert>
#include <vector>
#include <functional>
#include <cmath>

std::vector<int> grayCode(int n) {
    int len = std::pow(2, n);
    std::function<bool(int pos, std::vector<int> &acc, std::vector<bool> &checked)> f;
    f = [&f, &n, &len](int pos, std::vector<int> &acc, std::vector<bool> &checked) -> bool {
        if (pos == len) {
            int count = 0;
            unsigned int mask = 1;
            for (int i = 0; i < n; ++i, mask <<= 1) {
                if ((acc[pos - 1] & mask) != 0) {
                    ++count;
                    if (count >= 2) {
                        return false;
                    }
                }
            }

            return true;
        }

        int val = acc[pos - 1];
        unsigned int mask = 1;
        for (int i = 0; i < n; ++i, mask <<= 1) {
            int new_val = val ^ mask;
            if (checked[new_val]) {
                continue;
            }

            acc[pos] = new_val;
            checked[new_val] = true;
            if (f(pos + 1, acc, checked)) {
                return true;
            }

            checked[new_val] = false;
        }

        return false;
    };

    std::vector<int> acc(len, -1);
    std::vector<bool> checked(len, false);
    acc[0] = 0;
    checked[0] = true;
    (void)f(1, acc, checked);
    return acc;
}

int main() {
    {
        std::vector<int> expected{0, 1, 3, 2};
        auto ret = grayCode(2);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{0, 1};
        auto ret = grayCode(1);
        assert(ret == expected);
    }
    return 0;
}
