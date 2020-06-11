#include <cassert>
#include <vector>
#include <cstdio>

bool lemonadeChange(const std::vector<int> &bills) {
    std::vector<int> remains(2);
    for (const auto bill : bills) {
        switch (bill) {
        case 5:
            ++remains[0];
            break;
        case 10:
            if (remains[0] == 0) {
                return false;
            }

            --remains[0];
            ++remains[1];
            break;
        case 20:
        default:
            if (remains[0] >= 1 && remains[1] >= 1) {
                --remains[1];
                --remains[0];
            } else if (remains[0] >= 3) {
                remains[0] -= 3;
            } else {
                return false;
            }

            break;
        }
    }

    return true;
}

int main() {
    assert(lemonadeChange(std::vector<int>{5, 5, 5, 10, 20}));
    assert(lemonadeChange(std::vector<int>{5, 5, 10}));
    assert(!lemonadeChange(std::vector<int>{10, 10}));
    assert(!lemonadeChange(std::vector<int>{5, 5, 10, 10, 20}));
    assert(lemonadeChange(std::vector<int>{5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5}));
    return 0;
}
