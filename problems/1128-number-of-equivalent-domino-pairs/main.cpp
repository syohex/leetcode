#include <cassert>
#include <vector>
#include <set>

int numEquivDominoPairs(const std::vector<std::vector<int>> &dominoes) {
    if (dominoes.size() == 1) {
        return 0;
    }

    std::set<size_t> checked;
    int ret = 0;
    for (size_t i = 0; i < dominoes.size() - 1; ++i) {
        if (checked.find(i) != checked.end()) {
            continue;
        }

        int n = 0;
        for (size_t j = i + 1; j < dominoes.size(); ++j) {
            if ((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) ||
                (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])) {
                ++n;
                checked.insert(j);
            }
        }

        if (n != 0) {
            ret += (n * (1 + n)) / 2;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2},
            {2, 1},
            {3, 4},
            {5, 6},
        };
        assert(numEquivDominoPairs(input) == 1);
    }
    return 0;
}
