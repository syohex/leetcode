#include <cassert>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int digits(int n) {
    int digits = 1;
    while (true) {
        n /= 10;
        if (n == 0) {
            break;
        }

        ++digits;
    }

    return digits;
}

std::string largestNumber(std::vector<int> &nums) {
    if (nums.empty()) {
        return "";
    }

    std::map<int, int> m;
    size_t zeros = 0;
    for (const auto n : nums) {
        if (n == 0) {
            ++zeros;
        }
        m[n] = digits(n);
    }

    if (zeros == nums.size()) {
        return "0";
    }

    std::sort(nums.begin(), nums.end(), [&m](int a, int b) {
        int digitsA = m[a];
        int digitsB = m[b];

        if (digitsA == digitsB) {
            return a > b;
        }

        int valA = static_cast<int>(a * pow(10, digitsB) + b);
        int valB = static_cast<int>(b * pow(10, digitsA) + a);
        return valA > valB;
    });

    std::string ret;
    for (const auto n : nums) {
        ret += std::to_string(n);
    }

    return ret;
}

int main() {
    assert(digits(9) == 1);
    assert(digits(0) == 1);
    assert(digits(99) == 2);
    assert(digits(12345) == 5);

    {
        std::vector<int> input{10, 2};
        assert(largestNumber(input) == "210");
    }
    {
        std::vector<int> input{3, 30, 34, 5, 9};
        assert(largestNumber(input) == "9534330");
    }
    {
        std::vector<int> input{0, 0};
        assert(largestNumber(input) == "0");
    }
    return 0;
}
