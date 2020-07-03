#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <climits>

std::string mostCommonWord(std::string &paragraph, const std::vector<std::string> &banned) {
    for (size_t i = 0; i < paragraph.size(); ++i) {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
            paragraph[i] += 'a' - 'A';
        }
    }

    size_t start = 0;
    while (true) {
        if (paragraph[start] >= 'a' && paragraph[start] <= 'z') {
            break;
        }
        ++start;
    }

    std::map<std::string, int> m;

    for (size_t i = start + 1; i < paragraph.size();) {
        if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
            ++i;
            continue;
        }

        ++m[paragraph.substr(start, i - start)];

        size_t orig = start;
        while (i < paragraph.size()) {
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
                start = i;
                break;
            }

            ++i;
        }

        if (start == orig) {
            start = paragraph.size();
        }
    }

    if (start < paragraph.size()) {
        m[paragraph.substr(start)];
    }

    for (const auto &ban : banned) {
        m.erase(ban);
    }

    std::string ret;
    int max = INT_MIN;
    for (const auto &it : m) {
        if (max < it.second) {
            max = it.second;
            ret.assign(it.first);
        }
    }

    return ret;
}

int main() {
    {
        std::string input("Bob hit a ball, the hit BALL flew far after it was hit.");
        std::vector<std::string> banned{"hit"};
        assert(mostCommonWord(input, banned) == "ball");
    }
    {
        std::string input("apple apple apple");
        std::vector<std::string> banned{"orange"};
        assert(mostCommonWord(input, banned) == "apple");
    }
    return 0;
}
