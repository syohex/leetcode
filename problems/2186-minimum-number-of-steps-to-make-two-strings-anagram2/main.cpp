#include <cassert>
#include <string>
#include <cmath>
#include <vector>

int minSteps(const std::string &s, const std::string &t) {
    std::vector<bool> cs(26, false);
    std::vector<int> s_table(26, 0);
    std::vector<int> t_table(26, 0);
    for (char c : s) {
        int index = c - 'a';
        cs[index] = true;
        ++s_table[index];
    }
    for (char c : t) {
        int index = c - 'a';
        cs[index] = true;
        ++t_table[index];
    }

    int ret = 0;
    for (int i = 0; i < 26; ++i) {
        if (cs[i]) {
            ret += std::abs(s_table[i] - t_table[i]);
        }
    }

    return ret;
}

int main() {
    assert(minSteps("leetcode", "coats") == 7);
    assert(minSteps("night", "thing") == 0);
    return 0;
}