#include <cassert>
#include <vector>
#include <string>

std::vector<std::string> stringMatching(const std::vector<std::string> &words) {
    std::vector<std::string> ret;
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = 0; j < words.size(); ++j) {
            if (i == j) {
                continue;
            }
            if (words[i].size() > words[j].size()) {
                continue;
            }

            if (words[j].find(words[i]) != std::string::npos) {
                ret.push_back(words[i]);
                break;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> input{"mass", "as", "hero", "superhero"};
        std::vector<std::string> expected{"as", "hero"};
        assert(stringMatching(input) == expected);
    }
    {
        std::vector<std::string> input{"leetcode", "et", "code"};
        std::vector<std::string> expected{"et", "code"};
        assert(stringMatching(input) == expected);
    }
    {
        std::vector<std::string> input{"blue", "green", "bu"};
        assert(stringMatching(input).empty());
    }
    return 0;
}