#include <cassert>
#include <string>
#include <vector>

bool isRobotBounded(const std::string &instructions) {
    std::vector<std::vector<int>> steps{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int index = 0;
    int x = 0;
    int y = 0;
    for (char c : instructions) {
        if (c == 'L') {
            index = (index + 3) % 4;
        } else if (c == 'R') {
            index = (index + 1) % 4;
        } else {
            x += steps[index][0];
            y += steps[index][1];
        }
    }

    return (x == 0 && y == 0) || index != 0;
}

int main() {
    assert(isRobotBounded("GGLLGG"));
    assert(!isRobotBounded("GG"));
    assert(isRobotBounded("GL"));
    return 0;
}
