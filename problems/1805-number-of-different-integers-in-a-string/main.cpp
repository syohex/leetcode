#include <cassert>
#include <string>
#include <cctype>
#include <set>

int numDifferentIntegers(const std::string &word) {
    std::set<std::string> s;
    size_t pos = 0;
    size_t limit = word.size();
    while (pos < limit) {
        while (pos < limit && !isdigit(word[pos])) {
            ++pos;
        }

        if (pos >= limit) {
            break;
        }

        while (pos < limit && word[pos] == '0') {
            ++pos;
        }

        size_t start = pos;
        while (pos < limit && isdigit(word[pos])) {
            ++pos;
        }

        if (start == pos) {
            s.insert("0");
        } else {
            s.insert(word.substr(start, pos - start));
        }
    }

    return static_cast<int>(s.size());
}

int main() {
    assert(numDifferentIntegers("a123bc34d8ef34") == 3);
    assert(numDifferentIntegers("leet1234code234") == 2);
    assert(numDifferentIntegers("a1b01c001") == 1);
    assert(numDifferentIntegers("aaaaa") == 0);
    assert(numDifferentIntegers("00000") == 1);
    assert(numDifferentIntegers("1234567789008289043948209890") == 1);
    assert(numDifferentIntegers("00a00b00c0d000e") == 1);
    return 0;
}
