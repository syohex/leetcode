#include <cassert>
#include <string>
#include <vector>

int countValidWords(const std::string &sentence) {
    std::vector<std::string> v;
    size_t pos = 0;
    size_t len = sentence.size();
    while (pos < len) {
        while (pos < len && sentence[pos] == ' ') {
            ++pos;
        }

        if (pos >= len) {
            break;
        }

        std::string tmp;
        while (pos < len && sentence[pos] != ' ') {
            tmp += sentence[pos++];
        }

        v.push_back(tmp);
    }

    const auto rule1 = [](const std::string &s) -> bool {
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                return false;
            }
        }

        return true;
    };

    const auto rule2 = [](const std::string &s) -> bool {
        int hyphens = 0;
        size_t len = s.size();
        for (size_t i = 0; i < len; ++i) {
            if (s[i] == '-') {
                if (hyphens != 0) {
                    return false;
                }

                if (i == 0 || i == len - 1) {
                    return false;
                }

                if (!(s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                    return false;
                }

                ++hyphens;
            }
        }

        return true;
    };

    const auto rule3 = [](const std::string &s) -> bool {
        size_t len = s.size();
        for (size_t i = 0; i < len; ++i) {
            switch (s[i]) {
            case '!':
            case '.':
            case ',':
                if (i != len - 1) {
                    return false;
                }
                break;
            default:
                break;
            }
        }

        return true;
    };

    int ret = 0;
    for (const auto &str : v) {
        if (!rule1(str)) {
            continue;
        }
        if (!rule2(str)) {
            continue;
        }
        if (!rule3(str)) {
            continue;
        }

        ++ret;
    }

    return ret;
}

int main() {
    assert(countValidWords("cat and   dog") == 3);
    assert(countValidWords("!this  1-s b8d!") == 0);
    assert(countValidWords("alice and  bob are playing stone-game10") == 5);
    assert(countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.") == 6);
    return 0;
}