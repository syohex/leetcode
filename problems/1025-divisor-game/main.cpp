#include <cassert>
#include <functional>
#include <cmath>
#include <map>

bool divisorGame(int N) {
    struct Arg {
        explicit Arg(int n, bool turn) : n(n), isAlice(turn) {
        }
        int n;
        int isAlice;

        bool operator==(const Arg &other) const {
            return n == other.n && isAlice == other.isAlice;
        }
        bool operator<(const Arg &other) const {
            return n < other.n;
        }
    };

    std::function<bool(const Arg &a)> f;
    std::map<Arg, bool> cache;
    f = [&f, &cache](const Arg &a) -> bool {
        if (a.n == 1) {
            return !a.isAlice;
        }

        int limit = static_cast<int>(std::sqrt(a.n));
        int ok = 0;
        int ret = 0;
        for (int i = 1; i <= limit; ++i) {
            if (a.n % i == 0) {
                ++ok;

                Arg next(a.n - i, !a.isAlice);
                bool aliceWin;
                if (cache.find(next) != cache.end()) {
                    aliceWin = cache[next];
                } else {
                    aliceWin = f(next);
                    cache[next] = aliceWin;
                }

                if (aliceWin) {
                    if (a.isAlice) {
                        return true;
                    }
                    ++ret;
                }
            }
        }

        return ok == ret;
    };

    return f(Arg(N, true));
}

int main() {
    assert(divisorGame(2));
    assert(!divisorGame(3));
    assert(divisorGame(4));
    assert(!divisorGame(5));
    assert(divisorGame(12));

    return 0;
}
