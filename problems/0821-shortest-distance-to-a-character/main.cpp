#include <cassert>
#include <vector>
#include <string>

std::vector<int> shortestToChar(const std::string &S, char C) {
    std::vector<int> ret;
    int left = -1;
    for (int i = 0; i < static_cast<int>(S.size()); ++i) {
        if (left == -1) {
            if (C == S[i]) {
                for (int j = 0; j <= i; ++j) {
                    ret.push_back(i - j);
                }

                left = i;
            }
        } else {
            if (C == S[i]) {
                int right = i;
                for (int j = left + 1; j <= right; ++j) {
                    if (j - left < right - j) {
                        ret.push_back(j - left);
                    } else {
                        ret.push_back(right - j);
                    }
                }

                left = i;
            }
        }
    }

    if (ret.size() != S.size()) {
        for (size_t i = left + 1, j = 1; i < S.size(); ++i, ++j) {
            ret.push_back(j);
        }
    }

    return ret;
}

int main() {
    {
        auto ret = shortestToChar("loveleetcode", 'e');
        std::vector<int> expected{3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
        assert(ret == expected);
    }
    {
        auto ret = shortestToChar("aaba", 'b');
        std::vector<int> expected{2, 1, 0, 1};
        assert(ret == expected);
    }
    return 0;
}
