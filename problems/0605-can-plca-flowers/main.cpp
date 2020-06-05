#include <cassert>
#include <vector>

bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    for (size_t i = 0; i < flowerbed.size() && n > 0; ++i) {
        if (flowerbed[i]) {
            continue;
        }

        int left = i == 0 ? 0 : flowerbed[i - 1];
        int right = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];

        if (left == 0 && right == 0) {
            flowerbed[i] = 1;
            --n;
        }
    }

    return n == 0;
}

int main() {
    {
        std::vector<int> input{1, 0, 0, 0, 1};
        assert(canPlaceFlowers(input, 1));
    }
    {
        std::vector<int> input{1, 0, 0, 0, 1};
        assert(!canPlaceFlowers(input, 2));
    }
    {
        std::vector<int> input{0, 0, 1, 0, 0};
        assert(canPlaceFlowers(input, 2));
    }
    {
        std::vector<int> input{0, 0, 1, 0, 0};
        assert(canPlaceFlowers(input, 1));
    }
    return 0;
}