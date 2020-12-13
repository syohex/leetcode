#include <cassert>
#include <string>

std::string interpret(std::string command) {
    size_t pos = 0;
    for (size_t i = 0; i < command.size();) {
        switch (command[i]) {
        case 'G':
            command[pos++] = 'G';
            ++i;
            break;
        case '(':
            if (command[i + 1] == ')') {
                command[pos++] = 'o';
                i += 2;
            } else {
                command[pos++] = 'a';
                command[pos++] = 'l';
                i += 4;
            }
            break;
        default:
            assert(!"never reach here");
            break;
        }
    }

    command.resize(pos);
    return command;
}

int main() {
    assert(interpret("G()(al)") == "Goal");
    assert(interpret("G()()()()(al)") == "Gooooal");
    assert(interpret("(al)G(al)()()G") == "alGalooG");
    return 0;
}