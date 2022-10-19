#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <utility>

std::vector<std::string> topKFrequent(const std::vector<std::string> &words, int k) {
    std::map<std::string, int> freq;
    for (const auto &word : words) {
        ++freq[word];
    }

    struct Data {
        std::string word;
        int count;
    };

    std::vector<Data> v;
    for (const auto &it : freq) {
        v.push_back({it.first, it.second});
    }

    std::sort(v.begin(), v.end(), [](const Data &a, const Data &b) {
        if (a.count == b.count) {
            return a.word < b.word;
        } else {
            return a.count > b.count;
        }
    });

    std::vector<std::string> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(v[i].word);
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"i", "love", "leetcode", "i", "love", "coding"};
        std::vector<std::string> expected{"i", "love"};
        auto ret = topKFrequent(words, 2);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
        std::vector<std::string> expected{"the", "is", "sunny", "day"};
        auto ret = topKFrequent(words, 4);
        assert(ret == expected);
    }
    return 0;
}
