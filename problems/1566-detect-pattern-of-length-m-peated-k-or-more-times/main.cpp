#include <cassert>
#include <vector>

bool containsPattern(const std::vector<int> &arr, int m, int k) {
    int len = arr.size();
    for (int i = 0; i < len - m + 1; ++i) {
        int count = 1;
        bool ok = true;
        for (int j = i + m; j < len - m + 1; j += m) {
            for (int n = 0; n < m; ++n) {
                if (arr[i + n] != arr[j + n]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ++count;
                if (count >= k) {
                    return true;
                }
            } else {
                break;
            }
        }
    }

    return false;
}

int main() {
    assert((containsPattern(std::vector<int>{2, 2}, 1, 2)));
    assert((containsPattern(std::vector<int>{1, 2, 4, 4, 4, 4}, 1, 3)));
    assert((containsPattern(std::vector<int>{1, 2, 1, 2, 1, 1, 1, 3}, 2, 2)));
    assert((!containsPattern(std::vector<int>{1, 2, 1, 2, 1, 3}, 2, 3)));
    assert((!containsPattern(std::vector<int>{1, 2, 3, 1, 2}, 2, 2)));
    return 0;
}
