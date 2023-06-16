#include <cassert>
#include <set>
#include <string>
#include <vector>

bool isFascinating(int n) {
    std::string tmp = std::to_string(n) + std::to_string(n * 2) + std::to_string(n * 3);
    std::vector<bool> checked(10, false);
    checked[0] = true;

    for (char c : tmp) {
        if (checked[c - '0']) {
            return false;
        }

        checked[c - '0'] = true;
    }

    return true;
}

int main() {
    assert(isFascinating(192));
    assert(!isFascinating(100));
    assert(!isFascinating(267));
    return 0;
}
