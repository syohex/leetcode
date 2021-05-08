#include <cassert>
#include <vector>
#include <cmath>
#include <string>
#include <vector>

int superpalindromesInRange(const std::string &left, const std::string &right) {
    long left_num = std::stol(left);
    long right_num = std::stol(right);
    long start = std::sqrt(left_num);
    if (start * start < left_num) {
        start += 1;
    }
    long end = std::sqrt(right_num);

    const auto is_palindrome = [](long n) {
        int nums[64] = {};
        int p = 0;
        while (n > 0) {
            nums[p++] = n % 10;
            n /= 10;
        }

        long half = p / 2;
        for (long i = 0; i < half; ++i) {
            if (nums[i] != nums[p - i - 1]) {
                return false;
            }
        }

        return true;
    };

    int ret = 0;
    for (long i = start; i <= end; ++i) {
        if (is_palindrome(i) && is_palindrome(i * i)) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(superpalindromesInRange("4", "1000") == 4);
    assert(superpalindromesInRange("1", "2") == 1);
    return 0;
}
