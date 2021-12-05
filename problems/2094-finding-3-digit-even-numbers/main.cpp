#include <cassert>
#include <vector>
#include <functional>
#include <set>
#include <cstdio>

std::vector<int> findEvenNumbers(const std::vector<int> &digits) {
    std::set<int> ret;
    int len = digits.size();
    std::function<void(int pos, int value, std::vector<bool> &checked)> f;
    f = [&](int pos, int value, std::vector<bool> &checked) {
        if (pos == len) {
            return;
        }

        for (int i = 0; i < len; ++i) {
            if (checked[i]) {
                continue;
            }

            if (value == 0 && digits[i] == 0) {
                continue;
            }
            if (value < 10) {
                checked[i] = true;
                f(pos + 1, 10 * value + digits[i], checked);
                checked[i] = false;
            } else {
                if (digits[i] % 2 != 0) {
                    continue;
                }

                ret.insert(10 * value + digits[i]);
            }
        }
    };

    std::vector<bool> checked(len, false);
    f(0, 0, checked);
    return std::vector<int>(ret.begin(), ret.end());
}

int main() {
    {
        std::vector<int> digits{2, 1, 3, 0};
        std::vector<int> expected{102, 120, 130, 132, 210, 230, 302, 310, 312, 320};
        auto ret = findEvenNumbers(digits);
        assert(ret == expected);
    }
    {
        std::vector<int> digits{2, 2, 8, 8, 2};
        std::vector<int> expected{222, 228, 282, 288, 822, 828, 882};
        auto ret = findEvenNumbers(digits);
        assert(ret == expected);
    }
    {
        std::vector<int> digits{3, 7, 5};
        auto ret = findEvenNumbers(digits);
        assert(ret.empty());
    }
    {
        std::vector<int> digits{0, 2, 0, 0};
        std::vector<int> expected{200};
        auto ret = findEvenNumbers(digits);
        assert(ret == expected);
    }
    {
        std::vector<int> digits{0, 0, 0};
        auto ret = findEvenNumbers(digits);
        assert(ret.empty());
    }
    return 0;
}
