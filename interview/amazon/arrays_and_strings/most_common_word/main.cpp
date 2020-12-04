#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <map>

std::string mostCommonWord(std::string &paragraph, const std::vector<std::string> &banned) {
    std::set<std::string> banned_set;
    for (const auto &b : banned) {
        banned_set.insert(b);
    }

    for (size_t i = 0; i < paragraph.size(); ++i) {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
            paragraph[i] = paragraph[i] + 'a' - 'A';
        }
    }

    std::map<std::string, int> word_count;
    std::string ret;
    int max = 0;
    size_t i = 0;
    while (i < paragraph.size()) {
        while (i < paragraph.size() && !(paragraph[i] >= 'a' && paragraph[i] <= 'z')) {
            ++i;
        }

        size_t start = i;
        while (i < paragraph.size() && paragraph[i] >= 'a' && paragraph[i] <= 'z') {
            ++i;
        }

        if (start == i) {
            continue;
        }

        std::string word(paragraph.substr(start, i - start));
        if (banned_set.find(word) == banned_set.end()) {
            ++word_count[word];
            if (word_count[word] > max) {
                ret = word;
                max = word_count[word];
            }
        }
    }

    return ret;
}

int main() {
    {
        std::string paragraph("Bob hit a ball, the hit BALL flew far after it was hit.");
        std::vector<std::string> banned{"hit"};
        assert(mostCommonWord(paragraph, banned) == "ball");
    }
    {
        std::string paragraph("Bob");
        std::vector<std::string> banned{};
        assert(mostCommonWord(paragraph, banned) == "bob");
    }
    {
        std::string paragraph("Bob    ");
        std::vector<std::string> banned{};
        assert(mostCommonWord(paragraph, banned) == "bob");
    }
    return 0;
}
