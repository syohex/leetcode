#include <cassert>
#include <vector>
#include <string>
#include <set>

int countPoints(const std::string &rings) {
    std::vector<std::set<char>> v(10);
    for (size_t i = 0; i < rings.size(); i += 2) {
        char color = rings[i];
        int num = rings[i + 1] - '0';
        v[num].insert(color);
    }

    int ret = 0;
    for (const auto &s : v) {
        if (s.size() == 3) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(countPoints("B0B6G0R6R0R6G9") == 1);
    assert(countPoints("B0R0G0R9R0B0G0") == 1);
    assert(countPoints("G4") == 0);
    return 0;
}
