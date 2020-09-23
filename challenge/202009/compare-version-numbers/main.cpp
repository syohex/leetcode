#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

std::vector<int> strToInts(const std::string &str) {
    std::vector<int> ret;
    int sum = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '.') {
            ret.push_back(sum);
            sum = 0;
        } else {
            sum = sum * 10 + str[i] - '0';
        }
    }
    ret.push_back(sum);
    return ret;
}

int compareVersion(const std::string &version1, const std::string &version2) {
    auto ver1 = strToInts(version1);
    auto ver2 = strToInts(version2);

    size_t limit = std::max(ver1.size(), ver2.size());
    for (size_t i = 0; i < limit; ++i) {
        int n1 = i < ver1.size() ? ver1[i] : 0;
        int n2 = i < ver2.size() ? ver2[i] : 0;

        if (n1 < n2) {
            return -1;
        } else if (n1 > n2) {
            return 1;
        }
    }

    return 0;
}

int main() {
    assert(compareVersion("1.01", "1.001") == 0);
    assert(compareVersion("1.0", "1.0.0") == 0);
    assert(compareVersion("0.1", "1.1") == -1);
    assert(compareVersion("1.0.1", "1") == 1);
    assert(compareVersion("7.5.2.4", "7.5.3") == -1);
    return 0;
}
