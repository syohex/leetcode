#include <cassert>
#include <string>
#include <vector>

bool arrayStringsAreEqual(const std::vector<std::string> &word1, const std::vector<std::string> &word2) {
    size_t i1 = 0, i2 = 0;
    size_t pos1 = 0, pos2 = 0;
    while (i1 < word1.size() && i2 < word2.size()) {
        if (word1[i1][pos1] != word2[i2][pos2]) {
            return false;
        }

        ++pos1;
        ++pos2;

        if (pos1 >= word1[i1].size()) {
            pos1 = 0;
            ++i1;
        }
        if (pos2 >= word2[i2].size()) {
            pos2 = 0;
            ++i2;
        }
    }

    return i1 == word1.size() && i2 == word2.size();
}

int main() {
    {
        std::vector<std::string> word1{"ab", "c"};
        std::vector<std::string> word2{"a", "bc"};
        assert(arrayStringsAreEqual(word1, word2));
    }
    {
        std::vector<std::string> word1{"a", "cb"};
        std::vector<std::string> word2{"ab", "c"};
        assert(!arrayStringsAreEqual(word1, word2));
    }
    {
        std::vector<std::string> word1{"abc", "d", "defg"};
        std::vector<std::string> word2{"abcddefg"};
        assert(arrayStringsAreEqual(word1, word2));
    }
    return 0;
}
