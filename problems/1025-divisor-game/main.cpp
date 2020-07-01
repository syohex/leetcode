#include <cassert>
#include <functional>
#include <cmath>

bool divisorGame(int N) {
    std::function<bool(int a, bool isAlice)> f;
    f = [&f](int a, bool isAlice) -> bool {
        if (a == 1) {
            return !isAlice;
        }

        int limit = static_cast<int>(std::sqrt(a));
        int ok = 0;
        int ret = 0;
        for (int i = 1; i <= limit; ++i) {
            if (a % i == 0) {
                ++ok;
                if (f(a - i, !isAlice)) {
                    ++ret;
                    if (isAlice) {
                        return true;
                    }
                }
            }
        }

        return ok == ret;
    };

    return f(N, true);
}

int main() {
    assert(divisorGame(2));
    assert(!divisorGame(3));
    assert(divisorGame(4));
    assert(!divisorGame(5));

    return 0;
}
