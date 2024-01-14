#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

bool closeStrings(const std::string &word1, const std::string &word2) {
    if (word1.size() != word2.size()) {
        return false;
    }

    std::vector<int> v1(26, 0);
    std::vector<int> v2(26, 0);
    std::set<char> s1, s2;

    for (size_t i = 0; i < word1.size(); ++i) {
        ++v1[word1[i] - 'a'];
        ++v2[word2[i] - 'a'];
        s1.insert(word1[i]);
        s2.insert(word2[i]);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    return v1 == v2 && s1 == s2;
}

int main() {
    assert(closeStrings("abc", "bca"));
    assert(!closeStrings("a", "aa"));
    assert(closeStrings("cabbba", "abbccc"));
    assert(!closeStrings("uau", "ssx"));
    return 0;
}
