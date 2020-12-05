#include <cassert>
#include <vector>
#include <cstdio>

bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    for (size_t i = 0; i < flowerbed.size() && n > 0; ++i) {
        if (flowerbed[i] == 1) {
            continue;
        }

        if (i == 0) {
            if (flowerbed.size() == 1 || flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        } else if (i == flowerbed.size() - 1) {
            if (flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        } else {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
    }

    return n == 0;
}

int main() {
    {
        std::vector<int> flowerbed{1, 0, 0, 0, 1};
        assert(canPlaceFlowers(flowerbed, 1));
    }
    {
        std::vector<int> flowerbed{1, 0, 0, 0, 1};
        assert(!canPlaceFlowers(flowerbed, 2));
    }
    {
        std::vector<int> flowerbed{0};
        assert(canPlaceFlowers(flowerbed, 1));
    }
    return 0;
}
