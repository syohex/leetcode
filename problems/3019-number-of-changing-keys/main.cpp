#include <cassert>
#include <string>
#include <cctype>

int countKeyChanges(const std::string &s) {
    char prev = std::tolower(s[0]);
    int ret = 0;

    for (size_t i = 1; i < s.size(); ++i) {
        char c = std::tolower(s[i]);
        if (c != prev) {
            ++ret;
        }
        prev = c;
    }
    return ret;
}

int main() {
    assert(countKeyChanges("aAbBcC") == 2);
    assert(countKeyChanges("AaAaAaaA") == 0);
    return 0;
}
