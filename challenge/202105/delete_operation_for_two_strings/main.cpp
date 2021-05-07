#include <cassert>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>

int minDistance(const std::string &word1, const std::string &word2) {
    int len1 = word1.size();
    int len2 = word2.size();

    std::vector<std::vector<int>> cache(len1, std::vector<int>(len2, 0));

    std::function<int(const std::string &a, const std::string &b, int pos1, int pos2)> f;
    f = [&f, &cache](const std::string &a, const std::string &b, int pos1, int pos2) -> int {
        if (pos1 < 0 || pos2 < 0) {
            return 0;
        }

        if (cache[pos1][pos2] != 0) {
            return cache[pos1][pos2];
        }

        if (a[pos1] == b[pos2]) {
            cache[pos1][pos2] = 1 + f(a, b, pos1 - 1, pos2 - 1);
        } else {
            cache[pos1][pos2] = std::max(f(a, b, pos1 - 1, pos2), f(a, b, pos1, pos2 - 1));
        }

        return cache[pos1][pos2];
    };

    int max_common_size = f(word1, word2, len1 - 1, len2 - 1);
    return len1 + len2 - (2 * max_common_size);
}

int main() {
    assert(minDistance("sea", "eat") == 2);
    assert(minDistance("leetcode", "etco") == 4);
    return 0;
}
