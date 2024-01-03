#include <cassert>
#include <vector>
#include <string>

int numberOfBeams(const std::vector<std::string> &bank) {
    int prev = 0;
    int ret = 0;
    for (const std::string &s : bank) {
        int ones = 0;
        for (char c : s) {
            if (c == '1') {
                ++ones;
            }
        }

        if (ones > 0) {
            ret += prev * ones;
            prev = ones;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> bank{
            "011001",
            "000000",
            "010100",
            "001000",
        };
        int ret = numberOfBeams(bank);
        assert(ret == 8);
    }
    {
        std::vector<std::string> bank{
            "000",
            "111",
            "000",
        };
        int ret = numberOfBeams(bank);
        assert(ret == 0);
    }
    return 0;
}
