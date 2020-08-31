#include <cassert>
#include <vector>

int compress(std::vector<char> &chars) {
    if (chars.size() <= 1) {
        return static_cast<int>(chars.size());
    }

    std::vector<int> tmp;
    int pos = 1;
    int count = 1;
    char prev = chars[0];
    for (size_t i = 1; i < chars.size(); ++i) {
        bool match = false;
        if (prev == chars[i]) {
            ++count;
            match = true;
        }

        if (!match || i == chars.size() - 1) {
            if (count > 1) {
                if (count >= 10) {
                    while (count > 0) {
                        tmp.push_back(count % 10);
                        count /= 10;
                    }
                    for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
                        chars[pos++] = *it + '0';
                    }
                    tmp.clear();
                } else {
                    chars[pos] = count + '0';
                    ++pos;
                }
            }

            if (!match) {
                chars[pos] = chars[i];
                prev = chars[i];
                count = 1;
                ++pos;
            }
        }
    }

    chars.resize(pos);

    return pos;
}

int main() {
    {
        std::vector<char> input{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        auto ret = compress(input);
        assert(ret == 6);
        assert((input == std::vector<char>{'a', '2', 'b', '2', 'c', '3'}));
    }
    {
        std::vector<char> input{'a'};
        auto ret = compress(input);
        assert(ret == 1);
        assert((input == std::vector<char>{'a'}));
    }
    {
        std::vector<char> input{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        auto ret = compress(input);
        assert(ret == 4);
        assert((input == std::vector<char>{'a', 'b', '1', '2'}));
    }
    {
        std::vector<char> input{'a', 'a', 'a', 'b', 'b', 'a', 'a'};
        auto ret = compress(input);
        assert(ret == 6);
        assert((input == std::vector<char>{'a', '3', 'b', '2', 'a', '2'}));
    }
    {
        std::vector<char> input{'a', 'b', 'c'};
        auto ret = compress(input);
        assert(ret == 3);
        assert((input == std::vector<char>{'a', 'b', 'c'}));
    }
    {
        std::vector<char> input{'a', 'a', 'a', 'a', 'a', 'b'};
        auto ret = compress(input);
        assert(ret == 3);
        assert((input == std::vector<char>{'a', '5', 'b'}));
    }
    return 0;
}
