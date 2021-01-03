#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {
    std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int> &a, const std::vector<int> &b) { return a[1] > b[1]; });

    int ret = 0;
    for (const auto &boxType : boxTypes) {
        int num = std::min(truckSize, boxType[0]);
        ret += num * boxType[1];
        truckSize -= num;
        if (truckSize == 0) {
            break;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 3},
            {2, 2},
            {3, 1},
        };
        assert(maximumUnits(input, 4) == 8);
    }
    {
        std::vector<std::vector<int>> input{
            {5, 10},
            {2, 5},
            {4, 7},
            {3, 9},
        };
        assert(maximumUnits(input, 10) == 91);
    }
    return 0;
}
