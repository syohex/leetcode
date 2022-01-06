#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <cstdio>

bool carPolling(const std::vector<std::vector<int>> &trips, int capacity) {
    std::map<int, std::vector<int>> in;
    std::map<int, std::vector<int>> out;
    std::set<int> v;

    for (const auto &trip : trips) {
        v.insert(trip[1]);
        v.insert(trip[2]);

        in[trip[1]].push_back(trip[0]);
        out[trip[2]].push_back(trip[0]);
    }

    int cap = 0;
    for (int pos : v) {
        if (out.find(pos) != out.end()) {
            for (int num : out.at(pos)) {
                cap -= num;
            }
        }
        if (in.find(pos) != in.end()) {
            for (int num : in.at(pos)) {
                cap += num;
            }
            if (cap > capacity) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> trips{{2, 1, 5}, {3, 3, 7}};
        assert(!carPolling(trips, 4));
    }
    {
        std::vector<std::vector<int>> trips{{2, 1, 5}, {3, 3, 7}};
        assert(carPolling(trips, 5));
    }
    {
        std::vector<std::vector<int>> trips{{2, 1, 5}, {3, 5, 7}};
        assert(carPolling(trips, 5));
    }
    {
        std::vector<std::vector<int>> trips{{9, 3, 4}, {9, 1, 7}, {4, 2, 4}, {7, 4, 5}};
        assert(carPolling(trips, 23));
    }
    return 0;
}
