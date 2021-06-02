#include <cassert>
#include <string>
#include <functional>

bool isInterleave(const std::string &s1, const std::string &s2, const std::string &s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    std::function<bool(size_t p1, size_t p2, size_t p)> f;
    f = [&f, &s1, &s2, &s3](size_t p1, size_t p2, size_t p) -> bool {
        if (p == s3.size()) {
            return true;
        }

        if (p1 < s1.size() && s1[p1] == s3[p]) {
            if (f(p1 + 1, p2, p + 1)) {
                return true;
            }
        }

        if (p2 < s2.size() && s2[p2] == s3[p]) {
            if (f(p1, p2 + 1, p + 1)) {
                return true;
            }
        }

        return false;
    };

    return f(0, 0, 0);
}

int main() {
    assert(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(isInterleave("", "", ""));
    return 0;
}
