#include <cassert>
#include <string>
#include <vector>

std::string restoreString(const std::string &s, const std::vector<int> &indices) {
    std::string ret(s.size(), 1);
    for (size_t i = 0; i < s.size(); ++i) {
        ret[indices[i]] = s[i];
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{4, 5, 6, 7, 0, 2, 1, 3};
        assert((restoreString("codeleet", input) == "leetcode"));
    }
    {
        std::vector<int> input{0, 1, 2};
        assert((restoreString("abc", input) == "abc"));
    }
    {
        std::vector<int> input{3, 1, 4, 2, 0};
        assert((restoreString("aiohn", input) == "nihao"));
    }
    {
        std::vector<int> input{4, 0, 2, 6, 7, 3, 1, 5};
        assert((restoreString("aaiougrt", input) == "arigatou"));
    }
    {
        std::vector<int> input{1, 0, 2};
        assert((restoreString("art", input) == "rat"));
    }
    return 0;
}
