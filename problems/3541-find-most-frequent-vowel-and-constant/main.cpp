#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

int maxFreqSum(const string &s) {
    int table[26] = {};
    int ret1 = 0;
    int ret2 = 0;
    for (char c : s) {
        int index = c - 'a';
        ++table[index];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ret1 = max(ret1, table[index]);
        } else {
            ret2 = max(ret2, table[index]);
        }
    }
    return ret1 + ret2;
}

int main() {
    assert(maxFreqSum("successes") == 6);
    assert(maxFreqSum("aeiaeia") == 3);
    return 0;
}
