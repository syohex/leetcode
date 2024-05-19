#include <cassert>
#include <string>
#include <cmath>
#include <vector>

int findPermutationDifference(const std::string &s, const std::string &t) {
    std::vector<int> sv(26, 0);
    std::vector<int> tv(26, 0);

    for (size_t i = 0; i < s.size(); ++i) {
        sv[s[i] - 'a'] = i;
    }
    for (size_t i = 0; i < t.size(); ++i) {
        tv[t[i] - 'a'] = i;
    }

    int sum = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';
        sum += std::abs(sv[index] - tv[index]);
    }

    return sum;
}

int main() {
    assert(findPermutationDifference("abc", "bac") == 2);
    assert(findPermutationDifference("abcde", "edbac") == 12);
    return 0;
}
