#include <cassert>
#include <functional>

bool divisorGame(int N) {
    std::function<bool(int a, bool isAlice)> f;
    f = [&f](int a, bool isAlice) -> bool {
        if (a == 1) {
            return !isAlice;
        }

        bool ret = true;
        for (int i = 1; i < a; ++i) {
            if (a % i == 0) {
                ret &= f(a - i, !isAlice);
            }
        }

        return ret;
    };

    return f(N, true);
}

int main() {
    assert(divisorGame(2));
    assert(!divisorGame(3));

    return 0;
}
