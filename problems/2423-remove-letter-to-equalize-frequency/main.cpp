#include <cassert>
#include <string>
#include <map>
#include <algorithm>
#include <limits>

bool equalFrequency(const std::string &word) {
    int freq[26] = {};
    for (char c : word) {
        ++freq[c - 'a'];
    }

    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();

    std::map<int, int> m;
    int chars = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] != 0) {
            ++chars;
            min = std::min(min, freq[i]);
            max = std::max(max, freq[i]);

            ++m[freq[i]];
        }
    }

    if (chars == 1) {
        return true;
    }

    if (m.size() == 1) {
        return min == 1;
    }

    if (m.size() != 2) {
        return false;
    }

    return (min == 1 && m[min] == 1) || (min + 1 == max && m[max] == 1);
}

int main() {
    {
        std::string word("abcc");
        assert(equalFrequency(word));
    }
    {
        std::string word("aazz");
        assert(!equalFrequency(word));
    }
    {
        std::string word("bac");
        assert(equalFrequency(word));
    }
    {
        std::string word("abbcc");
        assert(equalFrequency(word));
    }
    {
        std::string word("zz");
        assert(equalFrequency(word));
    }
    return 0;
}
