#include <cassert>
#include <string>
#include <vector>
#include <map>

std::string originalDigits(const std::string &s) {
    std::map<char, int> m;
    for (char c : s) {
        ++m[c];
    }

    std::vector<int> count(10, 0);
    count[0] = m['z'];
    count[2] = m['w'];
    count[4] = m['u'];
    count[6] = m['x'];
    count[8] = m['g'];
    count[3] = m['h'] - count[8];
    count[5] = m['f'] - count[4];
    count[7] = m['s'] - count[6];
    count[9] = m['i'] - count[5] - count[6] - count[8];
    count[1] = m['o'] - count[0] - count[2] - count[4];

    std::string ret;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            ret.push_back(i + '0');
        }
    }

    return ret;
}

int main() {
    assert(originalDigits("owoztneoer") == "012");
    assert(originalDigits("fviefuro") == "45");
    assert(originalDigits("zeroonetwothreefourfivesixseveneightnine") == "0123456789");
    return 0;
}
