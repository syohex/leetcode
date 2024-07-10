#include <cassert>
#include <vector>
#include <string>

int minOperations(const std::vector<std::string> &logs) {
    int depth = 0;
    for (const auto &log : logs) {
        if (log == "../") {
            if (depth > 0) {
                --depth;
            }
        } else if (log != "./") {
            ++depth;
        }
    }
    return depth;
}

int main() {
    {
        std::vector<std::string> logs{"d1/", "d2/", "../", "d21/", "./"};
        int ret = minOperations(logs);
        assert(ret == 2);
    }
    {
        std::vector<std::string> logs{"d1/", "d2/", "./", "d3/", "../", "d31/"};
        int ret = minOperations(logs);
        assert(ret == 3);
    }
    {
        std::vector<std::string> logs{"d1/", "../", "../", "../"};
        int ret = minOperations(logs);
        assert(ret == 0);
    }
    return 0;
}
