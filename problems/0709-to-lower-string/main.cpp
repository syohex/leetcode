#include <cassert>
#include <string>

std::string toLowerCase(const std::string &str) {
    std::string ret;
    for (const auto c : str) {
        if (c >= 'A' && c <= 'Z') {
            ret.push_back(c + 'a' - 'A');
        } else {
            ret.push_back(c);
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
