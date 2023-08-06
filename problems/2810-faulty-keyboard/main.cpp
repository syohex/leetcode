#include <cassert>
#include <string>
#include <algorithm>

std::string finalString(const std::string &s) {
    std::string ret;
    for (char c : s) {
        if (c == 'i') {
            std::reverse(ret.begin(), ret.end());
        } else {
            ret.push_back(c);
        }
    }
    return ret;
}

int main() {
    assert(finalString("string") == "rtsng");
    assert(finalString("poiinter") == "ponter");
    return 0;
}
