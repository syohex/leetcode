#include <cassert>
#include <string>

int minMaxDifference(int num) {
    const auto toNum = [](const std::string &s) -> int {
        int ret = 0;
        for (char c : s) {
            ret = ret * 10 + c - '0';
        }
        return ret;
    };

    std::string n = std::to_string(num);
    std::string min;
    for (size_t i = 0; i < n.size(); ++i) {
        if (n[0] == n[i]) {
            min.push_back('0');
        } else {
            min.push_back(n[i]);
        }
    }

    std::string max;
    size_t len = n.size();
    size_t non_nine = len;
    for (size_t i = 0; i < len; ++i) {
        if (n[i] != '9') {
            non_nine = i;
            break;
        }
    }

    for (size_t i = 0; i < n.size(); ++i) {
        if (non_nine < len && n[i] == n[non_nine]) {
            max.push_back('9');
        } else {
            max.push_back(n[i]);
        }
    }

    return toNum(max) - toNum(min);
}

int main() {
    assert(minMaxDifference(11891) == 99009);
    assert(minMaxDifference(90) == 99);
    return 0;
}
