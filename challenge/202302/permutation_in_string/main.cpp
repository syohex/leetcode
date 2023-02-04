#include <cassert>
#include <string>
#include <vector>

bool checkIncusion(const std::string &s1, const std::string &s2) {
    if (s1.size() > s2.size()) {
        return false;
    }

    std::vector<int> v1(26, 0);
    for (char c : s1) {
        v1[c - 'a'] += 1;
    }

    std::vector<int> freq(26, 0);
    for (size_t i = 0; i < s1.size(); ++i) {
        freq[s2[i] - 'a'] += 1;
    }

    if (v1 == freq) {
        return true;
    }

    for (size_t i = s1.size(); i < s2.size(); ++i) {
        freq[s2[i - s1.size()] - 'a'] -= 1;
        freq[s2[i] - 'a'] += 1;
        if (freq == v1) {
            return true;
        }
    }

    return false;
}

int main() {
    assert(checkIncusion("ab", "eidbaooo"));
    assert(!checkIncusion("ab", "eidboaoo"));
    return 0;
}
