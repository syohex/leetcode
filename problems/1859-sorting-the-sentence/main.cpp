#include <cassert>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <map>

std::string sortSentence(const std::string &s) {
    std::istringstream ss(s);
    std::string tmp;
    std::map<int, std::string> table;
    while (std::getline(ss, tmp, ' ')) {
        int len = tmp.size();
        int num = 0;
        int m = 1;
        int i = len - 1;
        while (isdigit(tmp[i])) {
            num += m * (tmp[i] - '0');
            m *= 10;
            --i;
        }

        table[num] = tmp.substr(0, i + 1);
    }

    std::string ret;
    for (auto it = table.begin(); it != table.end(); ++it) {
        ret += it->second;
        if (std::next(it) != table.end()) {
            ret += " ";
        }
    }

    return ret;
}

int main() {
    {
        std::string s("is2 sentence4 This1 a3");
        std::string expected("This is a sentence");
        auto got = sortSentence(s);
        assert(got == expected);
    }
    {
        std::string s("Myself2 Me1 I4 and3");
        std::string expected("Me Myself and I");
        auto got = sortSentence(s);
        assert(got == expected);
    }
    return 0;
}
