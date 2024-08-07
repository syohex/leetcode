#include <cassert>
#include <vector>
#include <string>

std::string numberToWords(int num) {
    const char *ones[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const char *teens[] = {"Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                           "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const char *tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    const auto to_string = [&](int n, std::string &acc) -> bool {
        bool need_space = !acc.empty();
        bool modified = false;
        if (n >= 100) {
            int m = n / 100;
            n %= 100;

            if (need_space) {
                acc.push_back(' ');
            }

            acc.append(ones[m - 1]);
            acc.append(" Hundred");

            need_space = true;
            modified = true;
        }
        if (n >= 10) {
            if (need_space) {
                acc.push_back(' ');
            }

            int m = n / 10;

            if (m >= 2) {
                acc.append(tens[m - 2]);
                n %= 10;
            } else {
                acc.append(teens[n - 10]);
                n = 0;
            }

            need_space = true;
            modified = true;
        }
        if (n >= 1) {
            if (need_space) {
                acc.push_back(' ');
            }

            acc.append(ones[n - 1]);
            modified = true;
        }

        return modified;
    };

    if (num == 0) {
        return "Zero";
    }

    std::string acc;
    std::vector<std::pair<int, const char *>> v{
        {1'000'000'000, "Billion"}, {1'000'000, "Million"}, {1'000, "Thousand"}, {1, nullptr}};
    for (const auto &[n, unit] : v) {
        bool modified = to_string(num / n, acc);
        if (modified && unit != nullptr) {
            acc.push_back(' ');
            acc.append(unit);
        }

        num %= n;
    }

    return acc;
}

int main() {
    assert(numberToWords(0) == "Zero");
    assert(numberToWords(21) == "Twenty One");
    assert(numberToWords(1'000'000) == "One Million");
    assert(numberToWords(1'000'010) == "One Million Ten");
    assert(numberToWords(123) == "One Hundred Twenty Three");
    assert(numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five");
    assert(numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    assert(numberToWords(1234567899) ==
           "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety Nine");
    return 0;
}