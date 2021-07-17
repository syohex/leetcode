#include <cassert>
#include <string>

bool isDecomposable(const std::string &s) {
    bool has_two = false;
    char prev = s[0];
    int count = 1;
    for (size_t i = 1; i < s.size(); ++i) {
        if (prev != s[i]) {
            if (count == 2) {
                if (has_two) {
                    return false;
                }

                has_two = true;
            } else if (count != 3) {
                return false;
            }
            prev = s[i];
            count = 1;
        } else {
            if (count == 3) {
                count = 0;
            }

            ++count;
        }
    }

    if (has_two && count == 2) {
        return false;
    }
    if (!has_two && count == 2) {
        return true;
    }

    return has_two && count == 3;
}

int main() {
    assert(!isDecomposable("000111000"));
    assert(isDecomposable("00011111222"));
    assert(!isDecomposable("011100022233"));
    assert(!isDecomposable("0"));
    assert(!isDecomposable("0011"));
    return 0;
}
