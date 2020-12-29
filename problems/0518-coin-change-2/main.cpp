#include <cassert>
#include <vector>

int change(int amount, const std::vector<int> &coins) {
    std::vector<int> table(amount + 1, 0);
    table[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            table[i] += table[i - coin];
        }
    }

    return table[amount];
}

int main() {
    assert((change(5, std::vector<int>{1, 2, 5}) == 4));
    assert((change(3, std::vector<int>{2}) == 0));
    assert((change(10, std::vector<int>{10}) == 1));
    return 0;
}
