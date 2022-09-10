#include <cassert>
#include <vector>
#include <string>
#include <cstdio>

bool checkDistances(const std::string &s, const std::vector<int> &distance) {
    int len = s.size();
    std::vector<int> v(26, -1);

    for (int i = 0; i < len; ++i) {
        int index = s[i] - 'a';
        if (v[index] != -1) {
            if (i - v[index] - 1 != distance[index]) {
                return false;
            }
        }

        v[index] = i;
    }

    return true;
}

int main() {
    {
        std::string s("abaccb");
        std::vector<int> distance{1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        bool ret = checkDistances(s, distance);
        assert(ret);
    }
    {
        std::string s("aa");
        std::vector<int> distance{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        bool ret = checkDistances(s, distance);
        assert(!ret);
    }
    {
        std::string s("zz");
        std::vector<int> distance{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

        bool ret = checkDistances(s, distance);
        assert(!ret);
    }
    return 0;
}
