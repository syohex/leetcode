#include <cassert>
#include <vector>
#include <string>

std::string shiftingLetters(std::string &s, const std::vector<int> &shifts) {
    int len = s.size();
    std::vector<long> acc(len);

    long sum = 0;
    for (int i = len - 1; i >= 0; --i) {
        sum += shifts[i];
        acc[i] = sum;
    }

    for (int i = 0; i < len; ++i) {
        s[i] = ((s[i] - 'a') + acc[i]) % 26 + 'a';
    }

    return s;
}

int main() {
    {
        std::string s("abc");
        std::vector<int> shifts{3, 5, 9};
        assert(shiftingLetters(s, shifts) == "rpl");
    }
    {
        std::string s("aaa");
        std::vector<int> shifts{1, 2, 3};
        assert(shiftingLetters(s, shifts) == "gfd");
    }
    return 0;
}