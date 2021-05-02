#include <cassert>
#include <string>

std::string replaceDigists(const std::string &s) {
    std::string ret = s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            char c = s[i - 1] + s[i] - '0';
            ret[i] = c;
        }
    }

    return ret;
}

int main() {
    assert(replaceDigists("a1c1e1") == "abcdef");
    assert(replaceDigists("a1b2c3d4e") == "abbdcfdhe");
    return 0;
}
