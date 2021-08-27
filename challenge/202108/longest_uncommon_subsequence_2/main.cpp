#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int findLUSlength(const std::vector<std::string> &strs) {
    const auto check = [](const std::string &a, const std::string &b) -> bool {
        int len_a = a.size();
        int len_b = b.size();
        if (len_a > len_b) {
            return false;
        }

		int i = 0;
        for (int j = 0; i < len_a && j < len_b; ++j) {
            if (a[i] == b[j]) {
                ++i;
            }
        }

        return i == len_a;
    };

    int ret = -1;
    size_t len = strs.size();
    for (size_t i = 0; i < len; ++i) {
        bool ok = true;
        for (size_t j = 0; j < len; ++j) {
            if (i != j) {
                if (check(strs[i], strs[j])) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            ret = std::max(ret, static_cast<int>(strs[i].size()));
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> strs{"aba", "cdc", "eae"};
        assert(findLUSlength(strs) == 3);
    }
    {
        std::vector<std::string> strs{"aaa", "aaa", "aa"};
        assert(findLUSlength(strs) == -1);
    }
    return 0;
}
