#include <cassert>
#include <string>

std::string truncateSentence(const std::string &s, int k) {
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            ++count;
            if (count == k) {
                return s.substr(0, i);
            }
        }
    }

    return s;
}

int main() {
    assert(truncateSentence("Hello how are you contestant", 4) == "Hello how are you");
    assert(truncateSentence("What is the solution to this problem", 4) == "What is the solution");
    assert(truncateSentence("chopper is not a tanuki", 5) == "chopper is not a tanuki");
    return 0;
}