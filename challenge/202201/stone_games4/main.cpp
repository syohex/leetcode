#include <cassert>
#include <map>
#include <cmath>
#include <functional>

bool winnerSquareGame(int n) {
    std::map<int, bool> cache;
    cache[0] = false;

    std::function<bool(int remain)> f;
    f = [&](int remain) -> bool {
        if (cache.find(remain) != cache.end()) {
            return cache[remain];
        }

        int limit = std::sqrt(remain);
        for (int i = 1; i <= limit; ++i) {
            if (!f(remain - (i * i))) {
                cache[remain] = true;
                return true;
            }
        }

        cache[remain] = false;
        return false;
    };

    return f(n);
}

int main() {
    assert(winnerSquareGame(1));
    assert(!winnerSquareGame(2));
    assert(winnerSquareGame(4));
    return 0;
}
