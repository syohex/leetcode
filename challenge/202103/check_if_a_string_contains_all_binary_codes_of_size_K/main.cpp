#include <cassert>
#include <string>
#include <set>

bool hasAllCodes(const std::string &s, int k) {
    if (s.size() < static_cast<size_t>(k)) {
        return 0;
    }

    std::set<std::string> substrs;
    size_t goal = 1 << k;

    size_t limit = s.size() - k + 1;
    for (size_t i = 0; i < limit; ++i) {
        const auto substr = s.substr(i, k);
        if (substrs.find(substr) == substrs.end()) {
            substrs.insert(substr);
            if (substrs.size() >= goal) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    assert(hasAllCodes("00110110", 2));
    assert(hasAllCodes("00110", 2));
    assert(hasAllCodes("0110", 1));
    assert(!hasAllCodes("0110", 2));
    assert(!hasAllCodes("0000000001011100", 4));
    return 0;
}
