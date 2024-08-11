#include <cassert>
#include <string>
#include <algorithm>

std::string getEncryptedString(std::string s, int k) {
    std::rotate(s.begin(), s.begin() + k % s.size(), s.end());
    return s;
}

int main() {
    assert(getEncryptedString("dart", 3) == "tdar");
    assert(getEncryptedString("dart", 7) == "tdar");
    assert(getEncryptedString("aaa", 1) == "aaa");
    return 0;
}
