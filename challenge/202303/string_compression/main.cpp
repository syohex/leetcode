#include <cassert>
#include <vector>
#include <cstdio>

int compress(std::vector<char> &chars) {
    int pos = 0;
    int i = 0;
    int len = chars.size();

    while (i < len) {
        int n = 0;
        char c = chars[i];
        while (i < len && c == chars[i]) {
            ++i;
            ++n;
        }

        chars[pos++] = c;
        if (n > 1) {
            int digits[32] = {};
            int j = 0;
            while (n > 0) {
                digits[j++] = n % 10;
                n /= 10;
            }

            for (int k = j - 1; k >= 0; --k) {
                chars[pos++] = digits[k] + '0';
            }
        }
    }

    return pos;
}

int main() {
    {
        std::vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        std::vector<char> expected{'a', '2', 'b', '2', 'c', '3'};
        auto ret = compress(chars);
        assert(ret == 6);
        chars.resize(ret);
        assert(chars == expected);
    }
    {
        std::vector<char> chars{'a'};
        std::vector<char> expected{'a'};
        auto ret = compress(chars);
        assert(ret == 1);
        chars.resize(ret);
        assert(chars == expected);
    }
    {
        std::vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        std::vector<char> expected{'a', 'b', '1', '2'};
        auto ret = compress(chars);
        assert(ret == 4);
        chars.resize(ret);
        assert(chars == expected);
    }
    return 0;
}
