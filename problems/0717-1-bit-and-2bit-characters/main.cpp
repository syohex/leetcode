#include <cassert>
#include <cstdio>
#include <vector>

bool isOneBitCharacter(const std::vector<int> &bits) {
    for (size_t i = 0; i < bits.size();) {
        if (bits[i] == 1) {
            i += 2;
        } else {
            if (i == bits.size() - 1) {
                return true;
            }

            ++i;
        }
    }

    return false;
}

int main() {
    assert(isOneBitCharacter(std::vector<int>{1, 0, 0}));
    assert(!isOneBitCharacter(std::vector<int>{1, 1, 1, 0}));
    return 0;
}
