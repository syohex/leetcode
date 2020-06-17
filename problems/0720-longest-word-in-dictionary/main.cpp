#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::string longestWord(std::vector<std::string> &words) {
    std::set<std::string> s;
    for (const auto &word : words) {
        s.insert(word);
    }

    std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool { return a.size() > b.size(); });

    std::vector<std::string> candidates;
    for (const auto &word : words) {
        if (!candidates.empty()) {
            if (candidates[0].size() > word.size()) {
                break;
            }
        }

        bool found = true;
        for (size_t i = 1; i < word.size(); ++i) {
            std::string sub(word.substr(0, word.size() - i));
            if (s.find(sub) == s.end()) {
                found = false;
                break;
            }
        }

        if (found) {
            candidates.push_back(word);
        }
    }

    if (candidates.empty()) {
        return "";
    }
    if (candidates.size() == 1) {
        return candidates.front();
    }

    std::sort(candidates.begin(), candidates.end(), [](const std::string &a, const std::string &b) -> bool {
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }

        return true;
    });

    return candidates[0];
}

int main() {
    {
        std::vector<std::string> input{"w", "wo", "wor", "worl", "world"};
        auto ret = longestWord(input);
        assert(ret == "world");
    }
    {
        std::vector<std::string> input{"a", "banana", "app", "appl", "ap", "apply", "apple"};
        auto ret = longestWord(input);
        assert(ret == "apple");
    }
    {
        std::vector<std::string> input{"m", "mo", "moc", "moch", "mocha", "l", "la", "lat", "latt", "latte", "c", "ca", "cat"};
        auto ret = longestWord(input);
        assert(ret == "latte");
    }
    {
        std::vector<std::string> input{"apple", "banana", "orange"};
        auto ret = longestWord(input);
        assert(ret == "");
    }
    {
        std::vector<std::string> input{"ts",   "e",    "x",    "pbhj",  "opto",   "xhigy", "erikz", "pbh", "opt", "erikzb", "eri",
                                       "erik", "xlye", "xhig", "optoj", "optoje", "xly",   "pb",    "xhi", "x",   "o"};
        auto ret = longestWord(input);
        assert(ret == "e");
    }
    return 0;
}
