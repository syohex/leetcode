#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

std::vector<int> powerfulIntegers(int x, int y, int bound) {
    if (bound < 2) {
        return std::vector<int>{};
    }

    std::set<int> s;
    int xx = 1;
    for (size_t i = 0;; ++i) {
        if (xx > bound) {
            break;
        }
        int yy = 1;
        for (size_t j = 0;; ++j) {
            if (xx + yy <= bound) {
                s.insert(xx + yy);
            } else {
                break;
            }

            if (y == 1) {
                break;
            }
            yy *= y;
        }

        if (x == 1) {
            break;
        }
        xx *= x;
    }

    std::vector<int> ret;
    for (const auto i : s) {
        ret.push_back(i);
    }

    return ret;
}

bool check(const std::vector<int> &got, const std::vector<int> &expected) {
    if (got.size() != expected.size()) {
        return false;
    }

    std::set<int> g, e;
    for (size_t i = 0; i < got.size(); ++i) {
        g.insert(got[i]);
        e.insert(expected[i]);
    }

    return g == e;
}

int main() {
    {
        auto got = powerfulIntegers(2, 3, 10);
        std::vector<int> expected{2, 3, 4, 5, 7, 9, 10};
        assert(check(got, expected));
    }
    {
        auto got = powerfulIntegers(3, 5, 15);
        std::vector<int> expected{2, 4, 6, 8, 10, 14};
        assert(check(got, expected));
    }
    {
        auto got = powerfulIntegers(2, 1, 10);
        std::vector<int> expected{2, 3, 5, 9};
        assert(check(got, expected));
    }
    {
        auto got = powerfulIntegers(1, 2, 10);
        std::vector<int> expected{2, 3, 5, 9};
        assert(check(got, expected));
    }

    return 0;
}
