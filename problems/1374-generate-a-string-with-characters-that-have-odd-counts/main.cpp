#include <cassert>
#include <string>

std::string generateTheString(int n) {
    if (n == 1) {
        return std::string(1, 'a');
    }
    if (n % 2 == 0) {
        return std::string(1, 'a') + std::string(n - 1, 'b');
    }

    return std::string(1, 'a') + std::string(1, 'b') + std::string(n - 2, 'c');
}

int main() {
    assert(generateTheString(4).size() == 4);
    assert(generateTheString(2).size() == 2);
    assert(generateTheString(7).size() == 7);
    return 0;
}
