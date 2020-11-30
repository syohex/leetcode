#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int compareVersion(const std::string &version1, const std::string &version2) {
    const auto to_numbers = [](const std::string &str) -> std::vector<int> {
        std::vector<int> ret;
        size_t limit = str.size();
        size_t i = 0;
        while (i < limit) {
            int n = 0;
            while (i < limit && (str[i] >= '0' && str[i] <= '9')) {
                n = (10 * n) + (str[i] - '0');
                ++i;
            }

            ret.push_back(n);
            if (i < limit && str[i] == '.') {
                ++i;
            }
        }
        return ret;
    };

    const auto v1 = to_numbers(version1);
    const auto v2 = to_numbers(version2);
    size_t limit = std::max(v1.size(), v2.size());
    for (size_t i = 0; i < limit; ++i) {
        int n1 = i < v1.size() ? v1[i] : 0;
        int n2 = i < v2.size() ? v2[i] : 0;

        if (n1 < n2) {
            return -1;
        }
        if (n1 > n2) {
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
