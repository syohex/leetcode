#include <cassert>
#include <string>
#include <algorithm>

int minPartitions(const std::string &n) {
    int ret = 0;
    for (const char c : n) {
        ret = std::max(ret, c - '0');
    }
    return ret;
}

int main() {
    assert(minPartitions("32") == 3);
    assert(minPartitions("82734") == 8);
    assert(minPartitions("27346209830709182346") == 9);
    return 0;
}
