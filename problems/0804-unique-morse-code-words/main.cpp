#include <cassert>
#include <vector>
#include <string>
#include <set>

int uniqueMorseRepresentations(const std::vector<std::string> &words) {
    const std::vector<std::string> cm{".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                                      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                                      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

    std::set<std::string> ret;
    std::string tmp;
    for (const auto &word : words) {
        for (const auto c : word) {
            tmp.append(cm[c - 'a']);
        }

        ret.insert(tmp);
        tmp.clear();
    }
    return ret.size();
}

int main() {
    {
        std::vector<std::string> input{"gin", "zen", "gig", "msg"};
        assert(uniqueMorseRepresentations(input) == 2);
    }
    return 0;
}
