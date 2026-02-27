#include <cassert>
#include <string>
#include <vector>

using namespace std;

string mapWordWeights(const vector<string> &words, const vector<int> &weights) {
    string ret;
    for (const auto &word : words) {
        int sum = 0;
        for (char c : word) {
            sum += weights[c - 'a'];
        }
        int index = sum % 26;
        ret.push_back('a' + 25 - index);
    }

    return ret;
}

int main() {
    {
        vector<string> words{"abcd", "def", "xyz"};
        vector<int> weights{5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
        auto ret = mapWordWeights(words, weights);
        assert(ret == "rij");
    }
    {
        vector<string> words{"a", "b", "c"};
        vector<int> weights{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        auto ret = mapWordWeights(words, weights);
        assert(ret == "yyy");
    }
    return 0;
}
