#include <cassert>
#include <cstdio>
#include <initializer_list>

bool isUgly(int num) {
    if (num == 0) {
        return false;
    }
    if (num == 1) {
        return true;
    }

    const auto f = [](int num, int div) -> int {
        while (true) {
            if (num % div == 0) {
                num /= div;
                if (num == 1 || num == -1) {
                    return num;
                }
            } else {
                return num;
            }
        }
    };

    for (const int div : {2, 3, 5}) {
        num = f(num, div);
        if (num == 1) {
            return true;
        }
        if (num == -1) {
            return false;
        }
    }

    return false;
}

int main() {
    assert(!isUgly(0));
    assert(isUgly(6));
    assert(isUgly(8));
    assert(!isUgly(14));
    return 0;
}
