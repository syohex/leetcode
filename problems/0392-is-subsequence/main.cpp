#include <cassert>
#include <string>
#include <map>
#include <vector>

bool isSubsequence(const std::string &s, const std::string &t) {
    std::map<char, std::vector<int>> m;
    for (int i = 0; i < static_cast<int>(t.size()); ++i) {
        m[t[i]].push_back(i);
    }

    int cur = -1;
    for (char c : s) {
        if (m.find(c) == m.end()) {
            return false;
        }

        bool found = false;
        for (int pos : m[c]) {
            if (cur < pos) {
                found = true;
                cur = pos;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(isSubsequence("abc", "ahbgdc"));
    assert(!isSubsequence("axc", "ahbgdc"));
    return 0;
}
