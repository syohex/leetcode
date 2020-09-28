#include <cassert>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstdio>

int maxSatisfaction(std::vector<int> &satisfaction) {
    std::sort(satisfaction.begin(), satisfaction.end());

    if (satisfaction.back() <= 0) {
        return 0;
    }

    int limit = static_cast<int>(satisfaction.size());
    if (satisfaction.front() >= 0) {
        int sum = 0;
        for (int i = 1; i <= limit; ++i) {
            sum += satisfaction[i - 1] * i;
        }

        return sum;
    }

    int max = INT_MIN;
    for (int i = 0; i < limit; ++i) {
        int sum = 0;
        for (int j = i, k = 1; j < limit; ++j, ++k) {
            sum += satisfaction[j] * k;
        }
        if (sum > max) {
            max = sum;
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> inputs{-1, -8, 0, 5, -9};
        assert(maxSatisfaction(inputs) == 14);
    }
    {
        std::vector<int> inputs{4, 3, 2};
        assert(maxSatisfaction(inputs) == 20);
    }
    {
        std::vector<int> inputs{-1, -4, -5};
        assert(maxSatisfaction(inputs) == 0);
    }
    {
        std::vector<int> inputs{-2, 5, -1, 0, 3, -3};
        assert(maxSatisfaction(inputs) == 35);
    }
    return 0;
}
