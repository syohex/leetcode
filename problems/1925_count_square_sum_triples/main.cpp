#include <cassert>
#include <set>

int countTriples(int n) {
    std::set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i * i);
    }

    int ret = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            int tmp = a * a + b * b;
            if (s.find(tmp) != s.end()) {
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    assert(countTriples(5) == 2);
    assert(countTriples(10) == 4);
    return 0;
}
