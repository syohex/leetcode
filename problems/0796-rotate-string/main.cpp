#include <cassert>
#include <string>
#include <vector>

bool rotateString(const std::string &A, const std::string &B) {
    if (A.empty() && B.empty()) {
        return true;
    }

    if (A.size() != B.size()) {
        return false;
    }

    std::vector<size_t> bPoss;
    for (size_t i = 0; i < B.size(); ++i) {
        if (A[0] == B[i]) {
            bPoss.push_back(i);
        }
    }

    if (bPoss.empty()) {
        return false;
    }

    for (auto bPos : bPoss) {
        bool ok = true;
        for (size_t i = 0; i < A.size(); ++i) {
            if (A[i] != B[(bPos + i) % A.size()]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return true;
        }
    }

    return false;
}

int main() {
    assert(!rotateString("a", "ab"));
    assert(!rotateString("abc", "xyz"));
    assert(rotateString("abcde", "cdeab"));
    assert(!rotateString("abcde", "abced"));
    assert(!rotateString("bbbacddceeb", "ceebbbacdd"));
    return 0;
}
