#include <cassert>
#include <vector>

std::vector<int> getNoZeroIntegers(int n) {
    const auto hasZero = [](int a) -> bool {
        while (a > 0) {
            if (a % 10 == 0) {
                return true;
            }

            a /= 10;
        }

        return false;
    };

    for (int i = 1; i < n; ++i) {
        if (!hasZero(i) && !hasZero(n - i)) {
            return std::vector<int>{i, n - i};
        }
    }

    return std::vector<int>{0, 0};
}

int main() {
    assert((getNoZeroIntegers(2) == std::vector<int>{1, 1}));
    assert((getNoZeroIntegers(11) == std::vector<int>{2, 9}));
    assert((getNoZeroIntegers(10000) == std::vector<int>{1, 9999}));
    assert((getNoZeroIntegers(69) == std::vector<int>{1, 68}));
    assert((getNoZeroIntegers(1010) == std::vector<int>{11, 999}));
    return 0;
}
