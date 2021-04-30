#include <cassert>
#include <vector>
#include <set>

std::vector<int> powerfulIntegers(int x, int y, int bound) {
    const auto pow = [](int n, int p) -> long {
        long ret = 1;
        for (int i = 0; i < p; ++i) {
            ret *= n;
        }

        return ret;
    };

    std::vector<long> xv, yv;
    if (x == 1) {
        xv.push_back(1);
    } else {
        for (int i = 0;; ++i) {
            long n = pow(x, i);
            if (n >= bound) {
                break;
            }

            xv.push_back(n);
        }
    }
    if (y == 1) {
        yv.push_back(1);
    } else {
        for (int i = 0;; ++i) {
            long n = pow(y, i);
            if (n >= bound) {
                break;
            }

            yv.push_back(n);
        }
    }

    std::set<int> s;
    for (int m : xv) {
        for (int n : yv) {
            if (m + n <= bound) {
                s.insert(m + n);
            } else {
                break;
            }
        }
    }

    return std::vector<int>(s.begin(), s.end());
}

int main() {
    {
        std::vector<int> expected{2, 3, 4, 5, 7, 9, 10};
        auto ret = powerfulIntegers(2, 3, 10);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{2, 4, 6, 8, 10, 14};
        auto ret = powerfulIntegers(3, 5, 15);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{2};
        auto ret = powerfulIntegers(1, 1, 2);
        assert(ret == expected);
    }
    return 0;
}
