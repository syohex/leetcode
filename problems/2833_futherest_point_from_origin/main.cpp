#include <cassert>
#include <string>
#include <algorithm>
#include <cmath>

int furthestDistanceFromOrigin(const std::string &moves) {
    int ls = 0;
    int rs = 0;
    int underscores = 0;

    for (char c : moves) {
        switch (c) {
        case 'L':
            ++ls;
            break;
        case 'R':
            ++rs;
            break;
        case '_':
            ++underscores;
            break;
        default:
            assert(!"never reach here");
        }
    }

    return std::abs(ls - rs) + underscores;
}

int main() {
    assert(furthestDistanceFromOrigin("L_RL__R") == 3);
    assert(furthestDistanceFromOrigin("_R__LL_") == 5);
    assert(furthestDistanceFromOrigin("_______") == 7);
    return 0;
}
