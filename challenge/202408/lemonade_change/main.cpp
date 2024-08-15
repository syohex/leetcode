#include <cassert>
#include <vector>
#include <cstdio>

bool lemonadeChange(const std::vector<int> &bills) {
    int fives = 0;
    int tens = 0;
    for (int bill : bills) {
        if (bill == 5) {
            fives += 1;
        } else if (bill == 10) {
            if (fives < 1) {
                return false;
            }

            fives -= 1;
            tens += 1;
        } else {
            if (fives >= 1 && tens >= 1) {
                fives -= 1;
                tens -= 1;
            } else if (fives >= 3) {
                fives -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> bills{5, 5, 5, 10, 20};
        assert(lemonadeChange(bills));
    }
    {
        std::vector<int> bills{5, 5, 10, 10, 20};
        assert(!lemonadeChange(bills));
    }
    {
        std::vector<int> bills{5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
        assert(lemonadeChange(bills));
    }
    return 0;
}
