#include <cassert>
#include <string>
#include <cstdio>

std::string decodeAtIndex(const std::string &S, int K) {
    std::string tape;
    for (char c : S) {
        if (c >= '0' && c <= '9') {
            std::string tmp = tape;
            int limit = c - '0';
            for (int i = 1; i < limit; ++i) {
                tmp += tape;
            }

            tape = tmp;
        } else {
            tape.push_back(c);
        }

        if (tape.size() >= static_cast<size_t>(K)) {
            return std::string{tape[K - 1]};
        }
    }

    return "";
}

int main() {
    {
        std::string s("leet2code3");
        auto ret = decodeAtIndex(s, 10);
        assert(ret == "o");
    }
    {
        std::string s("ha22");
        auto ret = decodeAtIndex(s, 5);
        assert(ret == "h");
    }
    {
        std::string s("a2345678999999999999999");
        auto ret = decodeAtIndex(s, 1);
        assert(ret == "a");
    }
    return 0;
}
