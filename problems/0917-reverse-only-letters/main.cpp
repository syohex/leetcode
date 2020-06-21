#include <cassert>
#include <string>
#include <cstdio>
#include <set>

std::string reverseOnlyLetters(const std::string &S) {
    std::string tmp;
    std::set<size_t> posSet;
    for (size_t i = 0; i < S.size(); ++i) {
        if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')) {
            tmp.push_back(S[i]);
        } else {
            posSet.insert(i);
        }
    }

    std::string ret;
    for (size_t i = 0, j = tmp.size() - 1; i < S.size(); ++i) {
        if (posSet.find(i) != posSet.end()) {
            ret.push_back(S[i]);
        } else {
            ret.push_back(tmp[j--]);
        }
    }

    return ret;
}

int main() {
    assert(reverseOnlyLetters("ab-cd") == "dc-ba");
    assert(reverseOnlyLetters("a-bC-dEf-ghIj") == "j-Ih-gfE-dCba");
    assert(reverseOnlyLetters("Test1ng-Leet=code-Q!") == "Qedo1ct-eeLg=ntse-T!");
    return 0;
}
