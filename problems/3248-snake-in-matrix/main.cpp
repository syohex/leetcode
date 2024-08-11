#include <cassert>
#include <vector>
#include <string>

int finalPositionOfSnake(int n, const std::vector<std::string> &commands) {
    int row = 0;
    int col = 0;

    for (const auto &command : commands) {
        if (command == "LEFT") {
            col -= 1;
        } else if (command == "DOWN") {
            row += 1;
        } else if (command == "RIGHT") {
            col += 1;
        } else {
            row -= 1;
        }
    }

    return row * n + col;
}

int main() {
    {
        std::vector<std::string> commands{"RIGHT", "DOWN"};
        int ret = finalPositionOfSnake(2, commands);
        assert(ret == 3);
    }
    {
        std::vector<std::string> commands{"DOWN", "RIGHT", "UP"};
        int ret = finalPositionOfSnake(2, commands);
        assert(ret == 1);
    }
    return 0;
}
