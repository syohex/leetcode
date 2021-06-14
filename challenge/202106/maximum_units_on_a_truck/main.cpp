#include <cassert>
#include <vector>
#include <algorithm>

int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {
    std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int> &a, const std::vector<int> &b) { return a[1] > b[1]; });

    int ret = 0;
    for (const auto &b : boxTypes) {
        int trucks = std::min(b[0], truckSize);
        truckSize -= trucks;
        ret += b[1] * trucks;

        if (trucks <= 0) {
            break;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> boxTypes{{1, 3}, {2, 2}, {3, 1}};
        assert(maximumUnits(boxTypes, 4) == 8);
    }
    {
        std::vector<std::vector<int>> boxTypes{{5, 10}, {2, 5}, {4, 7}, {3, 9}};
        assert(maximumUnits(boxTypes, 10) == 91);
    }
    return 0;
}
