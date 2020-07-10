#include <cassert>
#include <string>

bool backspaceCompare(std::string S, std::string T) {
    std::string tmpS, tmpT;
    for (char c : S) {
        if (c == '#') {
            if (!tmpS.empty()) {
                tmpS.pop_back();
            }
        } else {
            tmpS.push_back(c);
        }
    }
    for (char c : T) {
        if (c == '#') {
            if (!tmpT.empty()) {
                tmpT.pop_back();
            }
        } else {
            tmpT.push_back(c);
        }
    }

    return tmpS == tmpT;
}

int main() {
    assert(backspaceCompare("ab#c", "ad#c"));
    assert(backspaceCompare("ab##", "c#d#"));
    assert(backspaceCompare("a##c", "#a#c"));
    assert(!backspaceCompare("a#c", "b"));
    return 0;
}
