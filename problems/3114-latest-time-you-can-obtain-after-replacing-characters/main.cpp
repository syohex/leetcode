#include <cassert>
#include <string>

std::string findLatestTime(std::string s) {
    if (s[0] == '?') {
        if (s[1] >= '2' && s[1] <= '9') {
            s[0] = '0';
        } else {
            s[0] = '1';
        }
    }
    if (s[1] == '?') {
        if (s[0] == '1') {
            s[1] = '1';
        } else {
            s[1] = '9';
        }
    }
    if (s[3] == '?') {
        s[3] = '5';
    }
    if (s[4] == '?') {
        s[4] = '9';
    }
    return s;
}

int main() {
    assert(findLatestTime("1?:?4") == "11:54");
    assert(findLatestTime("0?:5?") == "09:59");
    assert(findLatestTime("??:??") == "11:59");
    assert(findLatestTime("?9:??") == "09:59");
    assert(findLatestTime("??:11") == "11:11");
    return 0;
}
