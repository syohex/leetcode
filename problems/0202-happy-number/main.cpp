#include <cassert>
#include <set>
#include <functional>

bool isHappy(int n) {
    const auto f = [](int m, int &num) -> bool {
        num = 0;
        while (m > 0) {
            int tmp = m % 10;
            num += (tmp * tmp);
            m /= 10;
        }

        return num == 1;
    };

    std::set<int> s{n};
    int num;
    while (true) {
        bool ok = f(n, num);
        if (ok) {
            return true;
        }
        if (s.find(num) != s.end()) {
            return false;
        }

        s.insert(num);
        n = num;
    }
}

int main() {
    assert(isHappy(19));
    return 0;
}
