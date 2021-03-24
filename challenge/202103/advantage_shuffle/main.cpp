#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> advantageCount(std::vector<int> &A, const std::vector<int> &B) {
    std::sort(A.begin(), A.end());

    std::vector<int> ret;
    std::vector<bool> checked(A.size(), false);
    for (int b : B) {
        bool found = false;
        for (size_t i = 0; i < A.size(); ++i) {
            if (checked[i]) {
                continue;
            }

            if (A[i] > b) {
                ret.push_back(A[i]);
                checked[i] = true;
                found = true;
                break;
            }
        }

        if (!found) {
            for (size_t i = 0; i < A.size(); ++i) {
                if (!checked[i]) {
                    ret.push_back(A[i]);
                    checked[i] = true;
                    break;
                }
            }
        }
    }

    for (size_t i = 0; i < checked.size(); ++i) {
        if (!checked[i]) {
            ret.push_back(A[i]);
        }
    }

    return ret;
}

bool check(const std::vector<int> &a, const std::vector<int> &b, int expected) {
    if (a.size() != b.size()) {
        return false;
    }

    int count = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) {
            ++count;
        }
    }

    return count == expected;
}

int main() {
    {
        std::vector<int> A{2, 7, 11, 15};
        std::vector<int> B{1, 10, 4, 11};
        auto ret = advantageCount(A, B);
        assert(check(ret, B, 4));
    }
    {
        std::vector<int> A{12, 24, 8, 32};
        std::vector<int> B{13, 25, 32, 11};
        auto ret = advantageCount(A, B);
        assert(check(ret, B, 3));
    }
    {
        std::vector<int> A{15448, 14234, 13574, 19893, 6475};
        std::vector<int> B{14234, 6475, 19893, 15448, 13574};
        auto ret = advantageCount(A, B);
        assert(check(ret, B, 4));
    }
    return 0;
}
