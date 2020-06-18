#include <cassert>
#include <string>
#include <vector>

std::vector<int> diStringMatch(const std::string &S) {
    std::vector<int> ret;
    int n = S[0] == 'I' ? 0 : S.size();
    int maxNum = n == 0 ? S.size() : S.size() - 1;
    int minNum = n == 0 ? 1 : 0;
    ret.push_back(n);

    for (size_t i = 1; i < S.size(); ++i) {
        if (S[i] == 'I') {
            ++n;
            if (n >= maxNum) {
                n = minNum;
                minNum += 1;
            } else {
                minNum = n + 1;
            }
        } else {
            --n;
            if (n <= minNum) {
                n = maxNum;
                maxNum -= 1;
            } else {
                maxNum = n - 1;
            }
        }

        ret.push_back(n);
    }
    ret.push_back(minNum);

    assert(ret.size() == S.size() + 1);
    return ret;
}

int main() {
    assert((diStringMatch("IDID") == std::vector<int>{0, 4, 1, 3, 2}));
    assert((diStringMatch("III") == std::vector<int>{0, 1, 2, 3}));
    assert((diStringMatch("DDI") == std::vector<int>{3, 2, 0, 1}));
    assert((diStringMatch("DDID") == std::vector<int>{4, 3, 0, 2, 1}));
    return 0;
}
