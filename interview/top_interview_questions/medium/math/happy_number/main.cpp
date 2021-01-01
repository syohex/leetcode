#include <cassert>
#include <cstdint>
#include <set>
#include <cstdio>

bool isHappy(int n) {
    std::int64_t v = n;
    std::set<std::int64_t> s;
    while (true) {
        std::int64_t sum = 0;
        while (v > 0) {
            auto mod = v % 10;
            sum += mod * mod;
            v /= 10;
        }

        if (sum == 1) {
            break;
        }

        if (s.find(sum) != s.end()) {
            return false;
        }

        s.insert(sum);
        v = sum;
    }

    return true;
}

int main() {
    assert(isHappy(19));
    assert(!isHappy(2));
    return 0;
}