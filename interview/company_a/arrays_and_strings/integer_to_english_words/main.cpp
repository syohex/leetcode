#include <cassert>
#include <string>

std::string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    const auto f = [](int n, const std::string &unit) {
        const char *one[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        const char *ten_times[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const char *ten[] = {"Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                             "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        std::string ret;
        if (n >= 100) {
            int v = n / 100;
            ret += one[v - 1];
            ret += " Hundred";
            n %= 100;
        }

        if (n >= 10) {
            if (n >= 20) {
                int d = n / 10;

                if (!ret.empty()) {
                    ret += ' ';
                }
                ret += ten_times[d - 2];
                n %= 10;
            } else {
                int m = n % 10;
                if (!ret.empty()) {
                    ret += ' ';
                }
                ret += ten[m];
                n = 0;
            }
        }

        if (n != 0) {
            if (!ret.empty()) {
                ret += ' ';
            }
            ret += one[n - 1];
        }

        if (!unit.empty()) {
            ret += ' ';
            ret += unit;
        }

        return ret;
    };

    constexpr int BILLION = 1'000'000'000;
    constexpr int MILLION = 1'000'000;
    constexpr int THOUSAND = 1'000;

    std::string ret;
    if (num >= BILLION) {
        ret += f(num / BILLION, "Billion");
        num %= BILLION;
    }
    if (num >= MILLION) {
        if (!ret.empty()) {
            ret += ' ';
        }
        ret += f(num / MILLION, "Million");
        num %= MILLION;
    }
    if (num >= THOUSAND) {
        if (!ret.empty()) {
            ret += ' ';
        }
        ret += f(num / THOUSAND, "Thousand");
        num %= THOUSAND;
    }

    if (num != 0) {
        if (!ret.empty()) {
            ret += ' ';
        }
        ret += f(num, "");
    }

    return ret;
}

int main() {
    const char *expected[] = {
        "Zero",   "One",    "Two",      "Three",    "Four",    "Five",    "Six",       "Seven",    "Eight",    "Nine",   "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty",
    };
    for (size_t i = 0; i <= 20; ++i) {
        assert(numberToWords(i) == expected[i]);
    }

    assert(numberToWords(123) == "One Hundred Twenty Three");
    assert(numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five");
    assert(numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    assert(numberToWords(1234567891) ==
           "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");
    return 0;
}
