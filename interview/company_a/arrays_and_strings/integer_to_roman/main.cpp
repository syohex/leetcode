#include <cassert>
#include <string>

std::string intToRoman(int num) {
    const auto f = [](int n, char one, char five, char ten) -> std::string {
        std::string ret;
        if (n >= 1 && n <= 3) {
            for (int i = 0; i < n; ++i) {
                ret += one;
            }

            return ret;
        }

        if (n == 4) {
            ret += one;
            ret += five;
            return ret;
        }

        if (n == 5) {
            ret += five;
            return ret;
        }

        if (n >= 6 && n <= 8) {
            ret += five;
            for (int i = 0; i < n - 5; ++i) {
                ret += one;
            }
            return ret;
        }

        ret += one;
        ret += ten;
        return ret;
    };

    std::string ret;
    if (num >= 1000) {
        // num < 4000
        ret += f(num / 1000, 'M', ' ', ' ');
        num %= 1000;
    }

    if (num >= 100) {
        ret += f(num / 100, 'C', 'D', 'M');
        num %= 100;
    }

    if (num >= 10) {
        ret += f(num / 10, 'X', 'L', 'C');
        num %= 10;
    }

    if (num == 0) {
        return ret;
    }

    return ret + f(num, 'I', 'V', 'X');
}

int main() {
    assert(intToRoman(1) == "I");
    assert(intToRoman(3) == "III");
    assert(intToRoman(4) == "IV");
    assert(intToRoman(9) == "IX");
    assert(intToRoman(10) == "X");
    assert(intToRoman(50) == "L");
    assert(intToRoman(58) == "LVIII");
    assert(intToRoman(1994) == "MCMXCIV");
    return 0;
}
