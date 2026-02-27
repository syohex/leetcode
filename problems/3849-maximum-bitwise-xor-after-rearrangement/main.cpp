#include <cassert>
#include <string>

using namespace std;

string maximumXor(const string &s, const string &t) {
    int ones = 0;
    int zeros = 0;
    for (char c : t) {
        if (c == '0') {
            ++zeros;
        } else {
            ++ones;
        }
    }

    string ret;
    for (char c : s) {
        if (c == '0') {
            if (ones > 0) {
                ret.push_back('1');
                --ones;
            } else {
                ret.push_back('0');
                --zeros;
            }
        } else {
            if (zeros > 0) {
                ret.push_back('1');
                --zeros;
            } else {
                ret.push_back('0');
                --ones;
            }
        }
    }

    return ret;
}

int main() {
    assert(maximumXor("101", "011") == "110");
    assert(maximumXor("0110", "1110") == "1101");
    assert(maximumXor("0101", "1001") == "1111");
    return 0;
}
