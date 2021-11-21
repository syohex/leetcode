#include <cassert>
#include <vector>

int wateringPlants(const std::vector<int> &plants, int capacity) {
    int ret = 0;
    int len = plants.size();
    int pos = 0;
    int water = capacity;
    while (pos < len) {
        if (water < plants[pos]) {
            ret += pos + pos + 1;
            water = capacity;
        } else {
            ret += 1;
        }

        water -= plants[pos];
        ++pos;
    }

    return ret;
}

int main() {
    {
        std::vector<int> plants{2, 2, 3, 3};
        assert(wateringPlants(plants, 5) == 14);
    }
    {
        std::vector<int> plants{1, 1, 1, 4, 2, 3};
        assert(wateringPlants(plants, 4) == 30);
    }
    {
        std::vector<int> plants{7, 7, 7, 7, 7, 7, 7};
        assert(wateringPlants(plants, 8) == 49);
    }
    return 0;
}