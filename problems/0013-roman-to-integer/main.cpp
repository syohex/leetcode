#include <cassert>
#include <string>

int romanToInt(const std::string &s) {
    int ret = 0;
    char prev = 0;
    for (const auto c : s) {
        switch (c) {
        case 'I':
            ret += 1;
            break;
        case 'V':
            if (prev == 'I') {
                ret += 3;
            } else {
                ret += 5;
            }
            break;
        case 'X':
            if (prev == 'I') {
                ret += 8;
            } else {
                ret += 10;
            }
            break;
        case 'L':
            if (prev == 'X') {
                ret += 30;
            } else {
                ret += 50;
            }
            break;
        case 'C':
            if (prev == 'X') {
                ret += 80;
            } else {
                ret += 100;
            }
            break;
        case 'D':
            if (prev == 'C') {
                ret += 300;
            } else {
                ret += 500;
            }
            break;
        case 'M':
            if (prev == 'C') {
                ret += 800;
            } else {
                ret += 1000;
            }
            break;
        }

        prev = c;
    }

    return ret;
}

int main() {
    assert(romanToInt("III") == 3);
    assert(romanToInt("IV") == 4);
    assert(romanToInt("IX") == 9);
    assert(romanToInt("LVIII") == 58);
    assert(romanToInt("MCMXCIV") == 1994);
    return 0;
}