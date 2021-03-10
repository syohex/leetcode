#include <cassert>
#include <string>

std::string intToRoman(int num) {
    struct Data {
        char c;
        int value;
    };

    Data thousand{'M', 1000};
    Data five_hundred{'D', 500};
    Data one_hundred{'C', 100};
    Data fifty{'L', 50};
    Data ten{'X', 10};
    Data five{'V', 5};
    Data one{'I', 1};

    const auto f = [](int value, int base, const Data &tenth, const Data &fifth, const Data &first, std::string &ret) {
        if (value == tenth.value - first.value) {
            ret += first.c;
            ret += tenth.c;
        } else if (value > fifth.value) {
            ret += fifth.c;

            int count = (value - fifth.value) / base;
            for (int i = 0; i < count; ++i) {
                ret += first.c;
            }
        } else if (value == fifth.value) {
            ret += fifth.c;
        } else if (value == fifth.value - first.value) {
            ret += first.c;
            ret += fifth.c;
        } else {
            int count = value / base;
            for (int i = 0; i < count; ++i) {
                ret += first.c;
            }
        }
    };

    std::string ret;
    for (int i = 0; i < num / 1000; ++i) {
        ret += 'M';
    }
    num %= 1000;

    f((num / 100) * 100, 100, thousand, five_hundred, one_hundred, ret);
    num %= 100;

    f((num / 10) * 10, 10, one_hundred, fifty, ten, ret);
    num %= 10;

    f(num, 1, ten, five, one, ret);
    return ret;
}

int main() {
    assert(intToRoman(3) == "III");
    assert(intToRoman(4) == "IV");
    assert(intToRoman(9) == "IX");
    assert(intToRoman(58) == "LVIII");
    assert(intToRoman(1994) == "MCMXCIV");
    return 0;
}
