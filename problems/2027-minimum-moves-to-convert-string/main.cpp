#include <cassert>
#include <string>

int minimumMoves(const std::string &s) {
    int ret = 0;
    for (size_t i = 0; i < s.size();) {
        if (s[i] == 'X') {
            ++ret;
            i += 3;
        } else {
            ++i;
        }
    }

    return ret;
}

int main() {
    assert(minimumMoves("XXX") == 1);
    assert(minimumMoves("XXOX") == 2);
    assert(minimumMoves("OOOO") == 0);
    return 0;
}