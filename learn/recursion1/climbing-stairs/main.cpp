#include <cassert>
#include <functional>
#include <map>
#include <cstdio>

int climbStaris(int n) {
    std::map<int, int> m;
    std::function<int(int rest)> f;
    f = [&f, &m](int rest) -> int {
        if (rest <= 0) {
            return 0;
        }
        if (rest == 1) {
            return 1;
        }
        if (rest == 2) {
            return 2;
        }

        int val1;
        auto it1 = m.find(rest - 1);
        if (it1 == m.end()) {
            val1 = f(rest - 1);
            m[rest - 1] = val1;
        } else {
            val1 = it1->second;
        }

        int val2;
        auto it2 = m.find(rest - 2);
        if (it1 == m.end()) {
            val2 = f(rest - 2);
            m[rest - 2] = val2;
        } else {
            val2 = it2->second;
        }
        return val1 + val2;
    };

    return f(n);
}

int main() {
    assert(climbStaris(2) == 2);
    assert(climbStaris(3) == 3);
    assert(climbStaris(45) == 1836311903);
    return 0;
}
