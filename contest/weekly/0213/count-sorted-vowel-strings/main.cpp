#include <cassert>
#include <cstdio>
#include <functional>
#include <map>

int countVowelStrings2(int n) {
    std::map<char, int> m{
        {'a', 5}, {'e', 4}, {'i', 3}, {'o', 2}, {'u', 1},
    };
    std::function<void(int n, int pos, char last)> f;
    int ret = 0;
    f = [&f, &ret, &m](int n, int pos, char last) {
        if (n == pos) {
            ++ret;
            return;
        }

        for (const auto c : {'a', 'e', 'i', 'o', 'u'}) {
            if (last == '\0' || m[last] >= m[c]) {
                f(n, pos + 1, c);
            }
        }
    };

    f(n, 0, '\0');
    printf("@@ n=%d, ret=%d\n", n, ret);
    return ret;
}

int countVowelStrings(int n) {
    int a[5] = {1, 1, 1, 1, 1};
    int sum = 5;
    for (int i = 1; i < n; ++i) {
        int a0 = sum;
        int a1 = a0 - a[0];
        int a2 = a1 - a[1];
        int a3 = a2 - a[2];
        int a4 = a3 - a[3];
        sum = a0 + a1 + a2 + a3 + a4;

        a[0] = a0;
        a[1] = a1;
        a[2] = a2;
        a[3] = a3;
        a[4] = a4;
    }

    return sum;
}

int main() {
    assert(countVowelStrings(1) == 5);
    assert(countVowelStrings(2) == 15);
    assert(countVowelStrings(33) == 66045);
    return 0;
}
