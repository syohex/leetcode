#include <cassert>
#include <string>

std::string defangIPaddr(const std::string &address) {
    std::string ret(address.size() + 6, 1);
    size_t i = 0;
    for (const char c : address) {
        if (c == '.') {
            ret[i++] = '[';
            ret[i++] = '.';
            ret[i++] = ']';
        } else {
            ret[i++] = c;
        }
    }

    return ret;
}

int main() {
    assert((defangIPaddr("1.1.1.1") == "1[.]1[.]1[.]1"));
    assert((defangIPaddr("255.100.50.0") == "255[.]100[.]50[.]0"));
    return 0;
}