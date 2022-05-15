#include <cassert>
#include <vector>
#include <algorithm>

int largestCombination(const std::vector<int> &candidates) {
    int max = *std::max_element(candidates.begin(), candidates.end());

    int ret = 0;
    for (int i = 1; i <= max; i <<= 1) {
        int sum = 0;
        for (int c : candidates) {
            if ((c & i) != 0) {
                sum += 1;
            }
        }

        ret = std::max(ret, sum);
    }

    return ret;
}

int main() {
    {
        std::vector<int> candidates{16, 17, 71, 62, 12, 24, 14};
        assert(largestCombination(candidates) == 4);
    }
    {
        std::vector<int> candidates{8, 8};
        assert(largestCombination(candidates) == 2);
    }
    return 0;
}
