#include <cassert>
#include <vector>
#include <queue>

int minStoneSum(const std::vector<int> &piles, int k) {
    std::priority_queue<int> q;
    for (int pile : piles) {
        q.push(pile);
    }

    for (int i = 0; i < k; ++i) {
        int n = q.top();
        q.pop();

        int m = n - (n / 2);
        q.push(m);
    }

    int ret = 0;
    while (!q.empty()) {
        ret += q.top();
        q.pop();
    }

    return ret;
}

int main() {
    {
        std::vector<int> piles{5, 4, 9};
        int ret = minStoneSum(piles, 2);
        assert(ret == 12);
    }
    {
        std::vector<int> piles{4, 3, 6, 7};
        int ret = minStoneSum(piles, 3);
        assert(ret == 12);
    }
    return 0;
}
