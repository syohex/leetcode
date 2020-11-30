#include <cassert>
#include <functional>
#include <map>
#include <stack>

int climbStairs(int n) {
    std::map<int, int> m;
    std::function<int(int pos, int n)> f;
    f = [&f, &m](int pos, int n) -> int {
        if (pos == n) {
            return 1;
        }
        if (pos > n) {
            return 0;
        }

        if (m.find(pos) != m.end()) {
            return m[pos];
        }

        m[pos] = f(pos + 1, n) + f(pos + 2, n);
        return m[pos];
    };

    return f(0, n);
}

int main() {
    assert(climbStairs(2) == 2);
    assert(climbStairs(3) == 3);
    return 0;
}
