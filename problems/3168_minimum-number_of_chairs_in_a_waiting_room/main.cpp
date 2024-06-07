#include <cassert>
#include <string>
#include <algorithm>

int minimumChairs(const std::string &s) {
    int ret = 0;
    int chairs = 0;
    for (char c : s) {
        if (c == 'E') {
            ++chairs;
        } else {
            --chairs;
        }
        ret = std::max(ret, chairs);
    }

    return ret;
}

int main() {
    assert(minimumChairs("EEEEEEE") == 7);
    assert(minimumChairs("ELELEEL") == 2);
    assert(minimumChairs("ELEELEELLL") == 3);
    return 0;
}
