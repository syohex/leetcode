#include <cassert>
#include <vector>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    std::vector<int> cs;
    while (x != 0) {
        cs.push_back(x % 10);
        x /= 10;
    }

    size_t size = cs.size();
    size_t limit = cs.size() / 2;
    for (size_t i = 0; i < limit; ++i) {
        if (cs[i] != cs[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(isPalindrome(121));
    assert(!isPalindrome(-121));
    assert(!isPalindrome(10));
    return 0;
}