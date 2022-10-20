#include <cassert>
#include <string>

std::string intToRoman(int num) {
    const auto f = [](int num, int base, char ten_char, char five_char, char one_char, std::string &ret) {
        int digit = num / base;
        if (digit == 9) {
            ret.push_back(one_char);
            ret.push_back(ten_char);
        } else if (digit >= 5 && digit <= 8) {
            ret.push_back(five_char);

            int count = digit - 5;
            for (int i = 0; i < count; ++i) {
                ret.push_back(one_char);
            }
        } else if (digit == 4) {
            ret.push_back(one_char);
            ret.push_back(five_char);
        } else {
            for (int i = 0; i < digit; ++i) {
                ret.push_back(one_char);
            }
        }
    };

    std::string ret;
    f(num % 10000, 1000, '!', '?', 'M', ret);
    f(num % 1000, 100, 'M', 'D', 'C', ret);
    f(num % 100, 10, 'C', 'L', 'X', ret);
    f(num % 10, 1, 'X', 'V', 'I', ret);

    return ret;
}

int main() {
    assert(intToRoman(3) == "III");
    assert(intToRoman(58) == "LVIII");
    assert(intToRoman(1994) == "MCMXCIV");
    return 0;
}
