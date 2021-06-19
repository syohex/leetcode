#include <cassert>
#include <vector>
#include <string>
#include <map>

bool makeEqual(const std::vector<std::string> &words) {
    std::map<char, int> m;
    for (const auto &word : words) {
        for (char c : word) {
            ++m[c];
        }
    }

    for (const auto &it : m) {
        if (it.second % words.size() != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::string> words{"abc", "aabc", "bc"};
        assert(makeEqual(words));
    }
    {
        std::vector<std::string> words{"ab", "a"};
        assert(!makeEqual(words));
    }
    {
        std::vector<std::string> words{"asdf"};
        assert(makeEqual(words));
    }
    return 0;
}