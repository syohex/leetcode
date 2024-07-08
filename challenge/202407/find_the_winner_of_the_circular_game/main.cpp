#include <cassert>
#include <vector>

int findTheWinner(int n, int k) {
    std::vector<int> v;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }

    int start = 0;
    while (v.size() > 1) {
        int removed_index = (start + k - 1) % v.size();
        v.erase(v.begin() + removed_index);
        start = removed_index;
    }

    return v[0];
}

int main() {
    assert(findTheWinner(5, 2) == 3);
    assert(findTheWinner(6, 5) == 1);
    return 0;
}
