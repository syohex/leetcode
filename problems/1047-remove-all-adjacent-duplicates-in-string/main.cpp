#include <string>
#include <cassert>

std::string removeDuplicates(const std::string &S) {
    std::string ret;
    for (const auto c : S) {
        if (ret.empty()) {
            ret.push_back(c);
        } else {
            if (ret.back() == c) {
                ret.pop_back();
            } else {
                ret.push_back(c);
            }
        }
    }
    return ret;
}

int main() {
    assert(removeDuplicates("aa") == "");
    assert(removeDuplicates("a") == "a");
    assert(removeDuplicates("aabb") == "");
    assert(removeDuplicates("aab") == "b");
    assert(removeDuplicates("abbaca") == "ca");
    return 0;
}
