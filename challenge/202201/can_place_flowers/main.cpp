#include <cassert>
#include <vector>

bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    int sum = 0;
    int len = flowerbed.size();
    std::vector<int> v(len, 0);
    for (int i = 0; i < len; ++i) {
        if (flowerbed[i] == 1) {
            continue;
        }

        if (i == 0) {
            if (len == 1 || flowerbed[i + 1] == 0) {
                flowerbed[0] = 1;
                ++sum;
            }
        } else if (i == len - 1) {
            if (flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                ++sum;
            }
        } else {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                ++sum;
            }
        }
    }

    return sum >= n;
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
        std::vector<int> flowerbed{0, 0, 1, 0};
        assert(!canPlaceFlowers(flowerbed, 2));
    }
    {
        std::vector<int> flowerbed{0};
        assert(canPlaceFlowers(flowerbed, 1));
    }
    {
        std::vector<int> flowerbed{0, 0, 0};
        assert(canPlaceFlowers(flowerbed, 2));
    }
    {
        std::vector<int> flowerbed{0, 0, 0, 1};
        assert(!canPlaceFlowers(flowerbed, 2));
    }
    {
        std::vector<int> flowerbed{0, 0, 1, 0, 1};
        assert(canPlaceFlowers(flowerbed, 1));
    }
}
