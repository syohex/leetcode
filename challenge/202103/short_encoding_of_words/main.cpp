#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int minimumLengthEncoding(const std::vector<std::string> &words) {
    std::set<std::string> s;
    size_t min_len = 2001;
    for (const auto &word : words) {
        s.insert(word);
        min_len = std::min(min_len, word.size());
    }

    std::vector<bool> checked(words.size(), false);
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = 0; j < words.size(); ++j) {
            if (checked[j] || words[i].size() <= words[j].size()) {
                continue;
            }

            size_t pos = words[i].size() - words[j].size();
            if (words[i].find(words[j], pos) != std::string::npos) {
                s.erase(words[j]);
                checked[j] = true;
            }
        }
    }

    int ret = 0;
    for (const auto &word : s) {
        ret += static_cast<int>(word.size()) + 1;
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"time", "me", "bell"};
        assert(minimumLengthEncoding(words) == 10);
    }
    {
        std::vector<std::string> words{"t"};
        assert(minimumLengthEncoding(words) == 2);
    }
    return 0;
}
