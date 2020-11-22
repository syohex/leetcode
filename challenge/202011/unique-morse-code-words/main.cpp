#include <cassert>
#include <vector>
#include <string>
#include <set>

int uniqueMorseRepresentations(const std::vector<std::string> &words) {
    const char *table[] = {".-", "-...", "-.-.", "-..",  ".",   "..-.", "--.", "....", "..",   ".---", "-.-",  ".-..", "--",
                           "-.", "---",  ".--.", "--.-", ".-.", "...",  "-",   "..-",  "...-", ".--",  "-..-", "-.--", "--.."};

    std::set<std::string> s;
    for (const auto &word : words) {
        std::string tmp;
        for (const auto c : word) {
            tmp += table[c - 'a'];
        }
        s.insert(tmp);
    }

    return static_cast<int>(s.size());
}

int main() {
    {
        std::vector<std::string> words{
            "gin",
            "zen",
            "gig",
            "msg",
        };
        assert(uniqueMorseRepresentations(words) == 2);
    }
    return 0;
}
