#include <cassert>
#include <string>
#include <set>
#include <utility>

bool isPathCrossing(const std::string &path) {
    std::set<std::pair<int, int>> s{std::make_pair(0, 0)};

    std::pair<int, int> p(0, 0);
    for (const auto c : path) {
        switch (c) {
        case 'N':
            ++p.second;
            break;
        case 'S':
            --p.second;
            break;
        case 'E':
            ++p.first;
            break;
        case 'W':
            --p.first;
            break;
        }

        if (s.find(p) != s.end()) {
            return true;
        }

        s.insert(p);
    }

    return false;
}

int main() {
    assert(!isPathCrossing("NES"));
    assert(isPathCrossing("NESWW"));
    return 0;
}
