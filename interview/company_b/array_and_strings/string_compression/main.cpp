#include <cassert>
#include <vector>
#include <string>

int compress(std::vector<char> &chars) {
    if (chars.empty()) {
        return 0;
    }

    char prev = chars[0];
    int pos = 0;
    int count = 1;
    for (size_t i = 1; i < chars.size(); ++i) {
        if (prev == chars[i]) {
            ++count;
        } else {
            chars[pos++] = prev;

            if (count > 1) {
                std::vector<char> tmp;
                while (count > 0) {
                    tmp.push_back(count % 10 + '0');
                    count /= 10;
                }
                for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
                    chars[pos++] = *it;
                }
            }

            prev = chars[i];
            count = 1;
        }
    }

    chars[pos++] = prev;
    if (count > 1) {
        std::vector<char> tmp;
        while (count > 0) {
            tmp.push_back(count % 10 + '0');
            count /= 10;
        }
        for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
            chars[pos++] = *it;
        }
    }

    return pos;
}

int main() {
    {
        std::vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        auto ret = compress(chars);
        chars.resize(ret);
        assert(ret == 6);
        assert((chars == std::vector<char>{'a', '2', 'b', '2', 'c', '3'}));
    }
    {
        std::vector<char> chars{'a'};
        auto ret = compress(chars);
        chars.resize(ret);
        assert(ret == 1);
        assert((chars == std::vector<char>{'a'}));
    }
    {
        std::vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        auto ret = compress(chars);
        chars.resize(ret);
        assert(ret == 4);
        assert((chars == std::vector<char>{'a', 'b', '1', '2'}));
    }
    {
        std::vector<char> chars{'a', 'a', 'a', 'b', 'b', 'a', 'a'};
        auto ret = compress(chars);
        chars.resize(ret);
        assert(ret == 6);
        assert((chars == std::vector<char>{'a', '3', 'b', '2', 'a', '2'}));
    }
    return 0;
}
