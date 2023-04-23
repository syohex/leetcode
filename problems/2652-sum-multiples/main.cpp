#include <cassert>

int sumMultiples(int n) {
    int ret = 0;

    for (int i = 3; i <= n; ++i) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            ret += i;
        }
    }
    return ret;
}
int main() {
    assert(sumMultiples(7) == 21);
    assert(sumMultiples(10) == 40);
    assert(sumMultiples(9) == 30);
    return 0;
}
