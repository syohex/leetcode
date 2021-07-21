#include <cassert>
#include <string>
#include <vector>

std::string pushDominoes(const std::string &dominoes) {
    int len = dominoes.size();
    std::vector<int> v(len);

    int value = 0;
    for (int i = 0; i < len; ++i) {
        switch (dominoes[i]) {
        case 'L':
            value = 0;
            break;
        case 'R':
            value = len;
            break;
        default:
            if (value != 0) {
                --value;
            }
            break;
        }

        v[i] = value;
    }

    for (int i = len - 1; i >= 0; --i) {
        switch (dominoes[i]) {
        case 'L':
            value = len;
            break;
        case 'R':
            value = 0;
            break;
        default:
            if (value != 0) {
                --value;
            }
            break;
        }

        v[i] -= value;
    }

    std::string ret(len, 0);
    for (int i = 0; i < len; ++i) {
        if (v[i] > 0) {
            ret[i] = 'R';
        } else if (v[i] == 0) {
            ret[i] = '.';
        } else {
            ret[i] = 'L';
        }
    }

    return ret;
}

int main() {
    assert(pushDominoes("RR.L") == "RR.L");
    assert(pushDominoes(".L.R...LR..L..") == "LL.RR.LLRRLL..");
    assert(pushDominoes("R....") == "RRRRR");
    assert(pushDominoes("....L") == "LLLLL");
    return 0;
}
