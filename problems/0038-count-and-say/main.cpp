#include <cassert>
#include <string>

std::string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }

    std::string prev("1");
    std::string ret;
    for (int i = 1; i < n; ++i) {
        ret = "";
        char p = prev[0];
        int cont = 1;
        for (size_t j = 1; j < prev.size(); ++j) {
            if (p == prev[j]) {
                ++cont;
                continue;
            }

            ret.push_back('0' + cont);
            ret.push_back(p);
            cont = 1;
            p = prev[j];
        }

        ret.push_back('0' + cont);
        ret.push_back(p);
        prev = ret;
    }

    return ret;
}

int main() {
    assert(countAndSay(1) == "1");
    assert(countAndSay(4) == "1211");

    for (int i = 1; i < 30; ++i) {
        printf("%02d == %s\n", i, countAndSay(i).c_str());
    }
    return 0;
}
