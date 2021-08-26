#include <cassert>
#include <string>
#include <vector>
#include <sstream>

bool isValidSerialization(const std::string &preorder) {
    std::vector<std::string> v;
    std::stringstream ss(preorder);
    std::string tmp;

    while (std::getline(ss, tmp, ',')) {
        v.push_back(tmp);
    }

    int nodes = 1;
    for (const auto &s : v) {
        --nodes;

        if (nodes < 0) {
            return false;
        }

        if (s != "#") {
            nodes += 2;
        }
    }

    return nodes == 0;
}

int main() {
    assert(isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
    assert(!isValidSerialization("1,#"));
    assert(isValidSerialization("1,#,#"));
    assert(!isValidSerialization("9,#,#,1"));
    assert(isValidSerialization("9,3,1,#,#,#,#"));
    return 0;
}
