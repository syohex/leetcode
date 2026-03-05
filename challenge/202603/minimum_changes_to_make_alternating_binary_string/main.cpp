#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

int minOperations(const string& s) {
    int count0{0};
    int count1{0};
    char c0 = '0';
    char c1 = '1';

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != c0) {
            ++count0;
        }
        if (s[i] != c1) {
            ++count1;
        }

        c0 = c0 == '0' ? '1' : '0';
        c1 = c1 == '0' ? '1' : '0';
    }

    return min(count0, count1);
}

int main() {
    assert(minOperations("0100") == 1);
    assert(minOperations("10") == 0);
    assert(minOperations("1111") == 2);
    assert(minOperations("1001") == 2);
    return 0;
}
