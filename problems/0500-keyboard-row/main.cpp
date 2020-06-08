#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>

std::vector<std::string> findWords(const std::vector<std::string> &words) {
    std::map<char, int> keyRowMap{
        {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},

        {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2},

        {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3},
    };

    std::vector<std::string> ret;
    for (const auto &word : words) {
        std::set<int> tmp;
        bool ok = true;
        for (const auto ch : word) {
            const char c = ch >= 'A' && ch <= 'Z' ? ch + 'a' - 'A' : ch;
            tmp.insert(keyRowMap[c]);
            if (tmp.size() >= 2) {
                ok = false;
                break;
            }
        }

        if (ok && tmp.size() == 1) {
            ret.push_back(word);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> input{"Hello", "Alaska", "Dad", "Peace"};
        std::vector<std::string> expected{"Alaska", "Dad"};
        assert(findWords(input) == expected);
    }
    return 0;
}
