#include <cassert>
#include <cmath>
#include <cstdio>

int reachNumber(int target) {
    target = std::abs(target);

    int sum = 0;
    int n = 0;
    while (sum < target) {
        sum += ++n;
    }

    if ((sum - target) % 2 == 0) {
        return n;
    }

    if (n % 2 == 0) {
        return n + 1;
    }
    
    return n + 2;
}

int main() {
    assert(reachNumber(3) == 2);
    assert(reachNumber(2) == 3);
    assert(reachNumber(4) == 3);
    assert(reachNumber(7) == 5);
    assert(reachNumber(5) == 5);
    return 0;
}
