#include <cassert>
#include <string>
#include <set>

bool isPathCrossing(const std::string &path) {
    int x = 0;
    int y = 0;
    std::set<std::pair<int, int>> visited;
    visited.insert({0, 0});
    for (char c : path) {
        switch (c) {
        case 'N':
            y += 1;
            break;
        case 'E':
            x += 1;
            break;
        case 'S':
            y -= 1;
            break;
        case 'W':
            x -= 1;
            break;
        default:
            assert(!"never reach here");
            break;
        }

        if (visited.find({x, y}) != visited.end()) {
            return true;
        }

        visited.insert({x, y});
    }

    return false;
}

int main() {
    assert(!isPathCrossing("NES"));
    assert(isPathCrossing("NESWW"));
    return 0;
}
