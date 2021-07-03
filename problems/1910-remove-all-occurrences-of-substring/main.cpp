#include <cassert>
#include <string>

std::string removeOccurrences(std::string &s, std::string &part) {
    size_t len = part.size();
    while (true) {
        size_t pos = s.find(part);
        if (pos == std::string::npos) {
            break;
        }

        s.replace(pos, len, "");
    }

    return s;
}

int main() {
    {
        std::string s("daabcbaabcbc");
        std::string part("abc");
        assert(removeOccurrences(s, part) == "dab");
    }
    {
        std::string s("axxxxyyyyb");
        std::string part("xy");
        assert(removeOccurrences(s, part) == "ab");
    }
    return 0;
}