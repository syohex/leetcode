#include <cassert>
#include <string>

bool areOccurrencesEqual(const std::string &s) {
    int counts[26] = {};
    for (char c : s) {
        ++counts[c - 'a'];
    }

    int count = 0;
    for (int n : counts) {
        if (n == 0) {
            continue;
        }

        if (count == 0) {
            count = n;
        } else if (count != n) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(areOccurrencesEqual("abacbc"));
    assert(!areOccurrencesEqual("aaabb"));
    return 0;
}