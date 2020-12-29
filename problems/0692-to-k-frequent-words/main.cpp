#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <map>

std::vector<std::string> topKFrequent(const std::vector<std::string> &words, int k) {
    struct Data {
        std::string word;
        int count;
    };

    const auto cmp = [](const Data &a, const Data &b) -> bool {
        if (a.count != b.count) {
            return a.count < b.count;
        }

        return a.word > b.word;
    };

    std::map<std::string, int> m;
    for (const auto &word : words) {
        ++m[word];
    }

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    for (const auto &it : m) {
        q.emplace(Data{it.first, it.second});
    }

    std::vector<std::string> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(q.top().word);
        q.pop();
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> input{"i", "love", "leetcode", "i", "love", "coding"};
        auto ret = topKFrequent(input, 2);
        assert((ret == std::vector<std::string>{"i", "love"}));
    }
    {
        std::vector<std::string> input{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
        auto ret = topKFrequent(input, 4);
        assert((ret == std::vector<std::string>{"the", "is", "sunny", "day"}));
    }
    return 0;
}
