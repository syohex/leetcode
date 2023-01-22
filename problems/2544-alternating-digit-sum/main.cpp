#include <cassert>
#include <vector>

int alternateDigitSum(int n) {
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    int sum = 0;
    bool is_positive = true;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        if (is_positive) {
            sum += *it;
        } else {
            sum -= *it;
        }
        is_positive = !is_positive;
    }

    return sum;
}

int main() {
    assert(alternateDigitSum(521) == 4);
    assert(alternateDigitSum(111) == 1);
    assert(alternateDigitSum(886996) == 0);
    return 0;
}
