#include <cassert>
#include <vector>
#include <algorithm>

int maxDistToClosest(const std::vector<int> &seats) {
    std::vector<int> v;
    int len = seats.size();
    for (int i = 0; i < len; ++i) {
        if (seats[i] == 1) {
            v.push_back(i);
        }
    }

    int ret = v[0];
    ret = std::max(ret, len - v.back() - 1);
    for (size_t i = 1; i < v.size(); ++i) {
        int dist = (v[i] - v[i - 1]) / 2;
        ret = std::max(ret, dist);
    }

    return ret;
}

int main() {
    {
        std::vector<int> seats{1, 0, 0, 0, 1, 0, 1};
        assert(maxDistToClosest(seats) == 2);
    }
    {
        std::vector<int> seats{1, 0, 0, 0};
        assert(maxDistToClosest(seats) == 3);
    }
    return 0;
}
