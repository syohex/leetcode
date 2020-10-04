#include <cassert>
#include <vector>
#include <string>

int minOperations(const std::vector<std::string> &logs) {
    int ret = 0;
    for (const auto &log : logs) {
        if (log == "./") {
            // do nothing
        } else if (log == "../") {
            if (ret > 0) {
                --ret;
            }
        } else {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> inputs{"d1/", "d2/", "../", "d21/", "./"};
        assert(minOperations(inputs) == 2);
    }
    {
        std::vector<std::string> inputs{"d1/", "d2/", "./", "d3/", "../", "d31/"};
        assert(minOperations(inputs) == 3);
    }
    {
        std::vector<std::string> inputs{"d1/", "../", "../", "../"};
        assert(minOperations(inputs) == 0);
    }
    return 0;
}
