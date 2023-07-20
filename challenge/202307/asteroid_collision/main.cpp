#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> asteroidCollision(const std::vector<int> &asteroids) {
    std::vector<int> ret;
    for (int asteroid : asteroids) {
        bool exploded = false;

        while (!ret.empty() && ret.back() > 0 && asteroid < 0) {
            int size = -asteroid;
            if (ret.back() < size) {
                ret.pop_back();
                continue;
            }
            if (ret.back() == size) {
                ret.pop_back();
            }

            exploded = true;
            break;
        }

        if (!exploded) {
            ret.push_back(asteroid);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> asteroids{5, 10, -5};
        std::vector<int> expected{5, 10};
        auto ret = asteroidCollision(asteroids);
        assert(ret == expected);
    }
    {
        std::vector<int> asteroids{8, -8};
        auto ret = asteroidCollision(asteroids);
        assert(ret.empty());
    }
    {
        std::vector<int> asteroids{10, 2, -5};
        std::vector<int> expected{10};
        auto ret = asteroidCollision(asteroids);
        assert(ret == expected);
    }
    return 0;
}
