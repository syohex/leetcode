#include <cassert>
#include <set>

int smallestRepunitDivByK(int k) {
    std::set<int> s;
    int num = 0;
    for (int i = 0; i < k; ++i) {
        num = (num * 10 + 1) % k;
        if (num == 0) {
            return i + 1;
        }
        if (s.find(num) != s.end()) {
            return -1;
        }
        s.insert(num);
    }

    return -1;
}

int main() {
    assert(smallestRepunitDivByK(1) == 1);
    assert(smallestRepunitDivByK(2) == -1);
    assert(smallestRepunitDivByK(3) == 3);
}
