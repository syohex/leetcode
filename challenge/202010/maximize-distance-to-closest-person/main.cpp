#include <cassert>
#include <vector>
#include <cstdio>

int maxDistToClosest(const std::vector<int> &seats) {
    std::vector<size_t> v;
    for (size_t i = 0; i < seats.size(); ++i) {
        if (seats[i] == 1) {
            v.push_back(i);
        }
    }

    size_t max = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        size_t diff = v[i] - v[i - 1];
        if (diff != 1) {
            diff /= 2;
        }

        if (max < diff) {
            max = diff;
        }
    }

    if (seats.size() - 1 - v.back() > max) {
        max = seats.size() - 1 - v.back();
    }

    return static_cast<int>(max);
}

int main() {
    {
        std::vector<int> input{1, 0, 0, 0, 1, 0, 1};
        assert(maxDistToClosest(input) == 2);
    }
    {
        std::vector<int> input{1, 0, 0, 0};
        assert(maxDistToClosest(input) == 3);
    }
    {
        std::vector<int> input{0, 0, 0, 1};
        assert(maxDistToClosest(input) == 3);
    }
    {
        std::vector<int> input{0, 1};
        assert(maxDistToClosest(input) == 1);
    }
    return 0;
}
