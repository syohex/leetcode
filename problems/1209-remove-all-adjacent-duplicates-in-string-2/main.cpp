#include <cassert>
#include <string>

std::string removeDuplicates(const std::string &s, int k) {
    std::string ret;
    for (size_t i = 0; i < s.size();) {
        if (ret.size() < k - 1) {
            size_t count = static_cast<size_t>(k - 1) - ret.size();
            ret.append(s.substr(i, count));
            i += count;
        } else {
            if (ret.back() == s[i]) {
                bool duplicated = true;
                for (int j = 0; j < k - 1; ++j) {
                    if (s[i] != ret[ret.size() - k + 1 + j]) {
                        duplicated = false;
                        break;
                    }
                }

                if (duplicated) {
                    ret.resize(ret.size() - (k - 1));
                } else {
                    ret.push_back(s[i]);
                }
            } else {
                ret.push_back(s[i]);
            }
            ++i;
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
