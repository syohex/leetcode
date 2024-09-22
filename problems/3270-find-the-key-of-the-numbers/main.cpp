#include <cassert>
#include <algorithm>

int generateKey(int num1, int num2, int num3) {
    const auto digit1 = [](int n) { return n % 10; };
    const auto digit2 = [](int n) { return (n / 10) % 10; };
    const auto digit3 = [](int n) { return (n / 100) % 10; };
    const auto digit4 = [](int n) { return (n / 1000) % 10; };

    int v1 = std::min({digit1(num1), digit1(num2), digit1(num3)});
    int v2 = std::min({digit2(num1), digit2(num2), digit2(num3)});
    int v3 = std::min({digit3(num1), digit3(num2), digit3(num3)});
    int v4 = std::min({digit4(num1), digit4(num2), digit4(num3)});

    return v4 * 1000 + v3 * 100 + v2 * 10 + v1;
}

int main() {
    assert(generateKey(1, 10, 1000) == 0);
    assert(generateKey(987, 879, 798) == 777);
    assert(generateKey(1, 2, 3) == 1);
    return 0;
}
