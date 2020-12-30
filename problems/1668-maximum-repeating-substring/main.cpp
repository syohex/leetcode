#include <cassert>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

int maxRepeating(const std::string &sequence, const std::string &word) {
    int ret = 0;
    for (size_t i = 0; i < sequence.size(); ++i) {
        if (strncmp(&sequence[i], &word[0], word.size()) != 0) {
            continue;
        }

        int count = 1;
        for (size_t j = i + word.size(); j < sequence.size(); j += word.size()) {
            if (strncmp(&sequence[j], &word[0], word.size()) != 0) {
                break;
            }

            ++count;
        }

        ret = std::max(ret, count);
    }

    return ret;
}

int main() {
    assert(maxRepeating("ababc", "ab") == 2);
    assert(maxRepeating("ababc", "ba") == 1);
    assert(maxRepeating("ababc", "ac") == 0);
    assert(maxRepeating("ababc", "a") == 1);
    assert(maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba") == 5);
    return 0;
}
