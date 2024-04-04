#include <cassert>
#include <string>
#include <algorithm>

int maxDepth(const std::string &s) {
    int ret = 0;
    int depth = 0;
    for (char c : s) {
        switch (c) {
        case '(':
            ++depth;
            ret = std::max(ret, depth);
            break;
        case ')':
            --depth;
            break;
        }
    }
    return ret;
}

int main() {
    assert(maxDepth("(1+(2*3)+((8)/4))") == 3);
    assert(maxDepth("(1)+((2))+(((3)))") == 3);
    return 0;
}
