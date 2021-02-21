#include <cassert>
#include <string>

std::string longestNiceSubString(const std::string &s) {
    std::string ret;
    int len = s.size();
    for (int i = 0; i < len - 1; ++i) {
        int lowers[26] = {};
        int uppers[26] = {};
        int c1 = s[i];
        if (c1 >= 'a' && c1 <= 'z') {
            ++lowers[c1 - 'a'];
        } else {
            ++uppers[c1 - 'A'];
        }

        for (int j = i + 1; j < len; ++j) {
            int c2 = s[j];
            if (c2 >= 'a' && c2 <= 'z') {
                ++lowers[c2 - 'a'];
            } else {
                ++uppers[c2 - 'A'];
            }

            bool valid = true;
            for (int k = 0; k < 26; ++k) {
                if ((lowers[k] > 0 && uppers[k] == 0) || (lowers[k] == 0 && uppers[k] > 0)) {
                    valid = false;
                    break;
                }
            }

            if (valid && (j - i + 1) > static_cast<int>(ret.size())) {
                ret = s.substr(i, j - i + 1);
            }
        }
    }
    return ret;
}

int main() {
    assert(longestNiceSubString("YazaAay") == "aAa");
    assert(longestNiceSubString("Bb") == "Bb");
    assert(longestNiceSubString("c") == "");
    assert(longestNiceSubString("dDzeE") == "dD");
    return 0;
}
