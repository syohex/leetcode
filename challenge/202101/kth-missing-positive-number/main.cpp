#include <cassert>
#include <vector>
#include <set>

int findKthPositive(const std::vector<int> &arr, int k) {
    std::set<int> s;
    for (int a : arr) {
        s.insert(a);
    }

    int count = 0;
    for (int i = 1;; ++i) {
        if (s.find(i) == s.end()) {
            ++count;
            if (count == k) {
                return i;
            }
        }
    }

    assert(!"never reach here");
    return 0;
}

int main() {
    assert((findKthPositive(std::vector<int>{2, 3, 4, 7, 11}, 5) == 9));
    assert((findKthPositive(std::vector<int>{1, 2, 3, 4}, 2) == 6));
    return 0;
}
