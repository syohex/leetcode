#include <cassert>
#include <vector>
#include <cstdio>

bool canPlaceFlowers(const std::vector<int> &flowerbed, int n) {
    int len = flowerbed.size();
    std::vector<int> v(len + 2, 0);
    for (int i = 0; i < len; ++i) {
        v[i + 1] = flowerbed[i];
    }

    for (int i = 1; i <= len; ++i) {
        if (v[i] == 1) {
            continue;
        }

        if (v[i - 1] == 0 && v[i + 1] == 0) {
            --n;

            if (n == 0) {
                return true;
            }
            v[i] = 1;
        }
    }

    return n <= 0;
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
        std::vector<int> flowerbed{0, 0, 1, 0, 1};
        assert(canPlaceFlowers(flowerbed, 1));
    }
    {
        std::vector<int> flowerbed{0};
        assert(canPlaceFlowers(flowerbed, 1));
    }
    {
        std::vector<int> flowerbed{1, 0, 1, 0, 1, 0, 1};
        assert(canPlaceFlowers(flowerbed, 0));
    }
    return 0;
}
