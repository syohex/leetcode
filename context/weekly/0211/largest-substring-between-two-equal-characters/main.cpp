#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <cstdio>

int maxLengthBetweenEqualCharacters(const std::string &s) {
    if (s.size() <= 1) {
        return -1;
    }

    std::map<char, std::vector<size_t>> m;
    for (size_t i = 0; i < s.size(); ++i) {
        m[s[i]].push_back(i);
    }

    int max = -1;
    for (const auto &it : m) {
        if (it.second.size() <= 1) {
            continue;
        }

        const auto &poss = it.second;
        for (size_t i = 0; i < poss.size() - 1; ++i) {
            for (size_t j = i + 1; j < poss.size(); ++j) {
                int length = static_cast<int>(poss[j] - poss[i]) - 1;
                if (length > max) {
                    max = length;
                }
            }
        }
    }

    return max;
}

int main() {
    assert(maxLengthBetweenEqualCharacters("aa") == 0);
    assert(maxLengthBetweenEqualCharacters("abca") == 2);
    assert(maxLengthBetweenEqualCharacters("cbzxy") == -1);
    assert(maxLengthBetweenEqualCharacters("cabbac") == 4);
    assert(maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv") == 18);
    return 0;
}
