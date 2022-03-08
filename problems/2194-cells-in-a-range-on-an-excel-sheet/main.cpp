#include <cassert>
#include <vector>
#include <string>

std::vector<std::string> cellsInRange(const std::string &s) {
    char column = s[0];
    char row = s[1];
    char end_column = s[3];
    char end_row = s[4];

    std::vector<std::string> ret;
    for (char i = column; i <= end_column; ++i) {
        for (char j = row; j <= end_row; ++j) {
            std::string tmp;
            tmp.push_back(i);
            tmp.push_back(j);
            ret.push_back(tmp);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> expected{"K1", "K2", "L1", "L2"};
        auto ret = cellsInRange("K1:L2");
        assert(ret == expected);
    }
    {
        std::vector<std::string> expected{"A1", "B1", "C1", "D1", "E1", "F1"};
        auto ret = cellsInRange("A1:F1");
        assert(ret == expected);
    }
    return 0;
}
