#include <cassert>
#include <string>
#include <sstream>

std::string complexNumberMultiply(const std::string &num1, const std::string &num2) {
    std::istringstream iss1(num1);
    std::istringstream iss2(num2);

    int a, b, c, d;
    char tmp;
    iss1 >> a >> tmp >> b;
    iss2 >> c >> tmp >> d;

    int e = a * c - (b * d);
    int f = a * d + (b * c);

    return std::to_string(e) + "+" + std::to_string(f) + "i";
}

int main() {
    assert(complexNumberMultiply("1+1i", "1+1i") == "0+2i");
    assert(complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");
    assert(complexNumberMultiply("2+1i", "-1+3i") == "-5+5i");
    return 0;
}
