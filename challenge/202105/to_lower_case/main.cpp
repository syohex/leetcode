#include <cassert>
#include <string>

std::string toLowerCase(const std::string &s) {
    std::string ret(s.size(), 0);
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ret[i] = s[i] + 'a' - 'A';
        } else {
            ret[i] = s[i];
        }
    }

    return ret;
}

int main() {
    assert(toLowerCase("Hello") == "hello");
    assert(toLowerCase("here") == "here");
    assert(toLowerCase("LOVELY") == "lovely");
    return 0;
}
