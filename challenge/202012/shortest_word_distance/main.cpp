#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

int shortestDistance(const std::vector<std::string> &words, const std::string &word1, const std::string &word2) {
    std::map<std::string, std::vector<int>> m;
    for (size_t i = 0; i < words.size(); ++i) {
        m[words[i]].push_back(i);
    }

    const auto &v1 = m[word1];
    const auto &v2 = m[word2];

    int ret = INT_MAX;
    for (const int i1 : v1) {
        for (const int i2 : v2) {
            ret = std::min(ret, std::abs(i1 - i2));
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"practice", "makes", "perfect", "coding", "makes"};
        assert(shortestDistance(words, "coding", "practice") == 3);
        assert(shortestDistance(words, "coding", "makes") == 1);
    }
    return 0;
}
