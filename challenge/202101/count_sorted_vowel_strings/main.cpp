#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <tuple>
#include <cstdio>

int countVowelStrings(int n) {
    int v[5] = {1, 1, 1, 1, 1};
    int sum = 5;

    for (int i = 1; i < n; ++i) {
        int a0 = sum;
        int a1 = a0 - v[0];
        int a2 = a1 - v[1];
        int a3 = a2 - v[2];
        int a4 = a3 - v[3];

        sum = a0 + a1 + a2 + a3 + a4;

        v[0] = a0;
        v[1] = a1;
        v[2] = a2;
        v[3] = a3;
        v[4] = a4;
    }

    return sum;
}

int countVowelStrings2(int n) {
    struct Data {
        int pos = 0;
        int prev = 0;

        bool operator<(const Data &other) const {
            return std::tie(pos, prev) < std::tie(other.pos, other.prev);
        }
    };

    std::map<Data, int> cache;

    std::function<int(int n, int pos, int prev)> f;
    f = [&f, &cache](int n, int pos, int prev) -> int {
        if (pos == n) {
            return 1;
        }

        const Data key{pos, prev};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int sum = 0;
        for (int i = prev; i >= 0; --i) {
            sum += f(n, pos + 1, i);
        }

        cache[key] = sum;
        return sum;
    };

    return f(n, 0, 4);
}

int main() {
    assert(countVowelStrings(1) == 5);
    assert(countVowelStrings(2) == 15);
    assert(countVowelStrings(33) == 66045);

    assert(countVowelStrings2(1) == 5);
    assert(countVowelStrings2(2) == 15);
    assert(countVowelStrings2(33) == 66045);

    printf("countVowelStrings(50) = %d\n", countVowelStrings(50));
    printf("countVowelStrings2(50) = %d\n", countVowelStrings2(50));
    return 0;
}
