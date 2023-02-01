#include <cassert>
#include <string>
#include <algorithm>
#include <vector>

std::string gcdOfStrings(const std::string &str1, const std::string &str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    int len = std::min(len1, len2);
    std::vector<int> common_divisors;
    for (int i = 1; i <= len; ++i) {
        if (len1 % i == 0 && len2 % i == 0) {
            common_divisors.push_back(i);
        }
    }

    for (auto it = common_divisors.rbegin(); it != common_divisors.rend(); ++it) {
        int n = *it;

        std::string s1 = str1.substr(0, n);
        std::string s2 = str2.substr(0, n);
        if (s1 != s2) {
            continue;
        }

        bool ok = true;
        for (int i = n; i < len1; i += n) {
            if (s1 != str1.substr(i, n)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }

        for (int i = n; i < len2; i += n) {
            if (s2 != str2.substr(i, n)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return s1;
        }
    }

    return "";
}

int main() {
    {
        std::string str1 = "ABCABC";
        std::string str2 = "ABC";
        auto ret = gcdOfStrings(str1, str2);
        assert(ret == "ABC");
    }
    {
        std::string str1 = "ABABAB";
        std::string str2 = "ABAB";
        auto ret = gcdOfStrings(str1, str2);
        assert(ret == "AB");
    }
    {
        std::string str1 = "LEET";
        std::string str2 = "CODE";
        auto ret = gcdOfStrings(str1, str2);
        assert(ret == "");
    }
    {
        std::string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX";
        std::string str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
        auto ret = gcdOfStrings(str1, str2);
        assert(ret == "TAUXX");
    }
    {
        std::string str1 = "AAAAAAAAA";
        std::string str2 = "AAACCC";
        auto ret = gcdOfStrings(str1, str2);
        assert(ret == "");
    }
    return 0;
}
