#include <cassert>
#include <string>
#include <vector>

int partitionString(const std::string &s) {
    std::vector<int> v(26, 0);

    int ret = 1;
    for (char c : s) {
        int index = c - 'a';
        if (v[index] != 0) {
            ++ret;

            for (int i = 0; i < 26; ++i) {
                v[i] = 0;
            }
        }

        ++v[index];
    }

    return ret;
}

int main() {
    {
        std::string s("abacaba");
        int ret = partitionString(s);
        assert(ret == 4);
    }
    {
        std::string s("ssssss");
        int ret = partitionString(s);
        assert(ret == 6);
    }
    return 0;
}