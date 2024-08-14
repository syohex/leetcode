#include <cassert>
#include <string>
#include <algorithm>

std::string getSmallestString(std::string s) {
    int len = s.size();
    for (int i = 1; i < len; ++i) {
        bool a = s[i] % 2 == 0;
        bool b = s[i - 1] % 2 == 0;
        if (a == b && s[i] < s[i - 1]) {
            std::swap(s[i], s[i - 1]);
            break;
        }
    }

    return s;
}

int main() {
    assert(getSmallestString("45320") == "43520");
    assert(getSmallestString("001") == "001");
    return 0;
}