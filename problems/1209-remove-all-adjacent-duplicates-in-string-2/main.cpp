#include <cassert>
#include <string>

std::string removeDuplicates(const std::string &s, int k) {
    std::string ret;
    for (const auto c : s) {
        if (ret.size() < k - 1) {
            ret.push_back(c);
        } else {
            bool duplicated = true;
            for (int i = 0; i < k - 1; ++i) {
                if (c != ret[ret.size() - i - 1]) {
                    duplicated = false;
                    break;
                }
            }

            if (duplicated) {
                for (int i = 0; i < k - 1; ++i) {
                    ret.pop_back();
                }
            } else {
                ret.push_back(c);
            }
        }
    }
    return ret;
}

int main() {
    assert(removeDuplicates("abcd", 2) == "abcd");
    assert(removeDuplicates("deeedbbcccbdaa", 3) == "aa");
    assert(removeDuplicates("abcd", 2) == "abcd");
    return 0;
}
