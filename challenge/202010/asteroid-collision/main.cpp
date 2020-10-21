#include <cassert>
#include <vector>
#include <cmath>
#include <cstdio>

std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
    if (asteroids.size() == 1) {
        return asteroids;
    }

    int limit = static_cast<int>(asteroids.size());
    for (int i = 0; i < limit; ++i) {
        if (asteroids[i] < 0) {
            int size = -asteroids[i];
            for (int j = i - 1; j >= 0; --j) {
                if (asteroids[j] == 0) {
                    continue;
                } else if (asteroids[j] < 0) {
                    break;
                }

                if (asteroids[j] > size) {
                    asteroids[i] = 0;
                    break;
                } else if (asteroids[j] == size) {
                    asteroids[i] = asteroids[j] = 0;
                    break;
                } else {
                    asteroids[j] = 0;
                }
            }

            continue;
        }
    }

    std::vector<int> ret;
    for (const auto i : asteroids) {
        if (i != 0) {
            ret.push_back(i);
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> inputs{5, 10, -5};
        auto ret = asteroidCollision(inputs);
        assert((ret == std::vector<int>{5, 10}));
    }
    {
        std::vector<int> inputs{8, -8};
        auto ret = asteroidCollision(inputs);
        assert(ret.empty());
    }
    {
        std::vector<int> inputs{10, 2, -5};
        auto ret = asteroidCollision(inputs);
        assert((ret == std::vector<int>{10}));
    }
    {
        std::vector<int> inputs{-2, -1, 1, 2};
        auto ret = asteroidCollision(inputs);
        assert((ret == std::vector<int>{-2, -1, 1, 2}));
    }
    {
        std::vector<int> inputs{100};
        auto ret = asteroidCollision(inputs);
        assert((ret == std::vector<int>{100}));
    }
    return 0;
}
