#include <cassert>

int subtractProductAndSum(int n) {
    int pro = 1, sum = 0;
    while (n > 0) {
        int m = n % 10;
        pro *= m;
        sum += m;

        n /= 10;
    }

    return pro - sum;
}

int main() {
    assert(subtractProductAndSum(234) == 15);
    assert(subtractProductAndSum(4421) == 21);
    return 0;
}
