#include <cassert>
#include <string>
#include <algorithm>

std::string licenseKeyFormatting(const std::string &S, int K) {
    std::string ret;
    int notDash = 0;
    bool lastIsDash = false;
    for (auto it = S.rbegin(); it != S.rend(); ++it) {
        if (*it != '-') {
            char c = *it >= 'a' && *it <= 'z' ? (*it - ('a' - 'A')) : *it;
            ret.push_back(c);
            ++notDash;
            lastIsDash = false;

            if (notDash % K == 0) {
                lastIsDash = true;
                ret.push_back('-');
            }
        }
    }

    if (lastIsDash) {
        ret.pop_back();
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(licenseKeyFormatting("5F3Z-2e-9-w", 4) == "5F3Z-2E9W");
    assert(licenseKeyFormatting("2-5g-3-J", 2) == "2-5G-3J");
    assert(licenseKeyFormatting("--a-a-a-a--", 2) == "AA-AA");
    return 0;
}
