#include <cassert>
#include <cstdio>
#include <climits>
#include <vector>

int reverse(int x) {
    if (x == INT_MIN) {
        return 0;
    }

    int sign = x < 0 ? -1 : 1;
    x = x < 0 ? -x : x;
    if (x < 10) {
        return x;
    }

    std::vector<int> n;

    while (x > 0) {
        n.push_back(x % 10);
        x /= 10;
    }

    int ret = 0;
    for (int i = static_cast<int>(n.size() - 1), j = 1; i >= 0; --i, j *= 10) {
        if (i == 0 && n[0] == 0) {
            break;
        }

        if (j >= 1'000'000'000) {
            if (n[i] >= 3) {
                return 0;
            }
            if (INT_MAX - ret < n[i] * j) {
                return 0;
            }
            ret += n[i] * j;
            break;
        } else {
            ret += n[i] * j;
        }
    }

    return ret * sign;
}

int main() {
    assert(reverse(1) == 1);
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    assert(reverse(1534236469) == 0);
    assert(reverse(-2147483412) == -2143847412);
    return 0;
}