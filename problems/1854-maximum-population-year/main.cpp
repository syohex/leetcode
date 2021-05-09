#include <cassert>
#include <vector>
#include <algorithm>

int maximumPopulation(const std::vector<std::vector<int>> &logs) {
    int ret = 2051;
    int max_population = 0;
    for (int i = 1950; i < 2050; ++i) {
        int population = 0;
        for (const auto &v : logs) {
            if (i >= v[0] && i < v[1]) {
                ++population;
            }
        }

        if (population > max_population) {
            max_population = population;
            ret = i;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> logs{
            {1993, 1999},
            {2000, 2010},
        };
        assert(maximumPopulation(logs) == 1993);
    }
    {
        std::vector<std::vector<int>> logs{
            {1950, 1961},
            {1960, 1971},
            {1970, 1981},
        };
        assert(maximumPopulation(logs) == 1960);
    }
    return 0;
}
