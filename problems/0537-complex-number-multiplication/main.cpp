#include <cassert>
#include <string>
#include <cstring>
#include <cstdio>

std::string complexNumberMultiply(const std::string &a, const std::string &b) {
    struct Complex {
        int real;
        int image;
    };

    Complex ac, bc;

    sscanf(a.c_str(), "%d+%di", &ac.real, &ac.image);
    sscanf(b.c_str(), "%d+%di", &bc.real, &bc.image);

    Complex ret{ac.real * bc.real - ac.image * bc.image, ac.real * bc.image + ac.image * bc.real};
    return std::to_string(ret.real) + "+" + std::to_string(ret.image) + "i";
}

int main() {
    assert(complexNumberMultiply("1+1i", "1+1i") == "0+2i");
    assert(complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");
    return 0;
}
