#include <cassert>
#include <functional>
#include <map>

int fib(int N) {
    std::map<int, int> m;
    std::function<int(int n)> f;
    f = [&f, &m](int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int prev2, prev1;
        auto it2 = m.find(n - 2);
        if (it2 == m.end()) {
            prev2 = f(n - 2);
            m[n - 2] = prev2;
        } else {
            prev2 = it2->second;
        }

        auto it1 = m.find(n - 1);
        if (it1 == m.end()) {
            prev1 = f(n - 1);
            m[n - 1] = prev1;
        } else {
            prev1 = it1->second;
        }

        return prev2 + prev1;
    };

    return f(N);
}

int main() {
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(13) == 233);

    return 0;
}
