#include <cassert>
#include <string>
#include <cctype>

std::string decodeAtIndex(const std::string &s, int k) {
    size_t total_length = 0;
    for (char c : s) {
        if (std::isdigit(c)) {
            total_length *= c - '0';
        } else {
            ++total_length;
        }
    }

    int len = s.size();
    size_t pos = k;
    for (int i = len - 1; i >= 0; --i) {
        pos %= total_length;
        if (pos == 0 && !std::isdigit(s[i])) {
            return std::string(1, s[i]);
        }

        if (std::isdigit(s[i])) {
            total_length /= s[i] - '0';
        } else {
            --total_length;
        }
    }

    assert(!"never reach here");
    return "";
}

int main() {
    {
        std::string s = "leet2code3";
        auto ret = decodeAtIndex(s, 10);
        assert(ret == "o");
    }
    {
        std::string s = "ha22";
        auto ret = decodeAtIndex(s, 5);
        assert(ret == "h");
    }
    {
        std::string s = "a2345678999999999999999";
        auto ret = decodeAtIndex(s, 1);
        assert(ret == "a");
    }
    return 0;
}
