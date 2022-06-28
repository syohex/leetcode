#include <cassert>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int minDeletions(const std::string &s) {
    std::vector<int> freq(26, 0);
    int max_freq = 0;
    for (char c : s) {
        ++freq[c - 'a'];

        max_freq = std::max(max_freq, freq[c - 'a']);
    }

    std::map<int, int> m;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] != 0) {
            ++m[freq[i]];
        }
    }

    std::priority_queue<int> q;
    for (int i = 1; i < max_freq; ++i) {
        if (m.find(i) == m.end()) {
            q.push(i);
        }
    }

    int ret = 0;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        int count = it->second;
        if (count == 1) {
            continue;
        }

        for (int i = 0; i < count - 1; ++i) {
            if (q.empty()) {
                ret += it->first;
                continue;
            }

            while (!q.empty() && q.top() > it->first) {
                q.pop();
            }

            if (q.empty()) {
                ret += it->first;
            } else {
                ret += it->first - q.top();
                q.pop();
            }
        }
    }

    return ret;
}

int main() {
    assert(minDeletions("aab") == 0);
    assert(minDeletions("aaabbbcc") == 2);
    assert(minDeletions("ceabaacb") == 2);
    assert(minDeletions("accdcdadddbaadbc") == 1);
    assert(minDeletions("bbcebab") == 2);
    return 0;
}
