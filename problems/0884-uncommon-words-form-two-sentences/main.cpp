#include <cassert>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> uncommonFromSetences(const std::string &A, const std::string &B) {
    std::map<std::string, int> m;

    size_t prev = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] == ' ') {
            ++m[A.substr(prev, i - prev)];
            prev = i + 1;
        }
    }
    if (prev != A.size()) {
        ++m[A.substr(prev, A.size() - prev)];
    }

    prev = 0;
    for (size_t i = 0; i < B.size(); ++i) {
        if (B[i] == ' ') {
            ++m[B.substr(prev, i - prev)];
            prev = i + 1;
        }
    }
    if (prev != B.size()) {
        ++m[B.substr(prev, B.size() - prev)];
    }

    std::vector<std::string> ret;
    for (const auto &it : m) {
        if (it.second == 1) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main() {
    const auto ret = uncommonFromSetences("this apple is sweet", "this apple is sour");
    assert((ret == std::vector<std::string>{"sweet", "sour"} || ret == std::vector<std::string>{"sour", "sweet"}));
    assert((uncommonFromSetences("apple apple", "banana") == std::vector<std::string>{"banana"}));
    return 0;
}
