#include <cassert>
#include <string>

std::string removeDuplicates(std::string &s, int k) {
    size_t limit = s.size();
    while (true) {
        char prev = s[0];
        int count = 1;

        size_t pos = 0;
        for (size_t i = 1; i < limit; ++i) {
            if (prev == s[i] && count < k) {
                ++count;
            } else {
                if (count < k) {
                    for (size_t j = 0; j < count; ++j) {
                        s[pos++] = prev;
                    }
                }
                prev = s[i];
                count = 1;
            }
        }

        if (count < k) {
            for (size_t j = 0; j < count; ++j) {
                s[pos++] = prev;
            }
        }

        if (limit == pos) {
            break;
        }

        limit = pos;
    }

    s.resize(limit);
    return s;
}

int main() {
    {
        std::string str("abcd");
        assert(removeDuplicates(str, 2) == "abcd");
    }
    {
        std::string str("deeedbbcccbdaa");
        assert(removeDuplicates(str, 3) == "aa");
    }
    {
        std::string str("pbbcggttciiippooaais");
        assert(removeDuplicates(str, 2) == "ps");
    }
    {
        std::string str("yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy");
        assert(removeDuplicates(str, 4) == "ybth");
    }
    return 0;
}
