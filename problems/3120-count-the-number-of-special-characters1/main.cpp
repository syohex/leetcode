#include <cassert>
#include <string>
#include <vector>
#include <cctype>

int numberOfSpecialChars(const std::string &word) {
    std::vector<bool> lowers(26, false);
    std::vector<bool> uppers(26, false);
    std::vector<bool> checked(26, false);

    int ret = 0;
    for (char c : word) {
        int index;
        if (c >= 'a' && c <= 'z') {
            index = c - 'a';
            lowers[index] = true;
        } else {
            index = c - 'A';
            uppers[index] = true;
        }

        if (!checked[index] && lowers[index] && uppers[index]) {
            ++ret;
            checked[index] = true;
        }
    }

    return ret;
}

int main() {
    assert(numberOfSpecialChars("aaAbcBC") == 3);
    assert(numberOfSpecialChars("abc") == 0);
    assert(numberOfSpecialChars("abBCab") == 1);
    return 0;
}
