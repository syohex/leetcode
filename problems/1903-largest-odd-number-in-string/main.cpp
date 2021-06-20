#include <cassert>
#include <string>

std::string largestOddNumber(const std::string &num) {
    int len = num.size();
    for (int i = len - 1; i >= 0; --i) {
        int n = num[i] - '0';
        if (n % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }

    return "";
}

int main() {
    assert(largestOddNumber("52") == "5");
    assert(largestOddNumber("4206") == "");
    assert(largestOddNumber("35427") == "35427");
    return 0;
}