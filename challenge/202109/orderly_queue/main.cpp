#include <cassert>
#include <string>
#include <algorithm>

std::string orderlyQueue(const std::string &s, int k) {
    std::string ret = s;
    if (k >= 2) {
        std::sort(ret.begin(), ret.end());
        return ret;
    }

    for (size_t i = 1; i < s.size(); ++i) {
        std::string tmp(s.substr(i) + s.substr(0, i));
        ret = std::min(ret, tmp);
    }

    return ret;
}

int main() {
    assert(orderlyQueue("cba", 1) == "acb");
    assert(orderlyQueue("baaca", 3) == "aaabc");
    return 0;
}
