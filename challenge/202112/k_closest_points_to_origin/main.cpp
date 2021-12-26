#include <cassert>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> kClosest(const std::vector<std::vector<int>> &points, int K) {
    struct Data {
        std::vector<int> point;
        double distance;
    };

    const auto cmp = [](const Data &a, const Data &b) -> bool { return a.distance > b.distance; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    for (const auto &point : points) {
        double distance = std::sqrt(point[0] * point[0] + point[1] * point[1]);
        q.push({point, distance});
    }

    std::vector<std::vector<int>> ret;
    for (int i = 0; i < K; ++i) {
        ret.push_back(q.top().point);
        q.pop();
    }
    return ret;
}

void check(const std::vector<std::vector<int>> &got, const std::vector<std::vector<int>> &expected) {
    assert(got.size() == expected.size());

    std::set<std::vector<int>> gs(got.begin(), got.end());
    std::set<std::vector<int>> es(expected.begin(), expected.end());
    assert(gs == es);
}

int main() {
    {
        std::vector<std::vector<int>> points{{1, 3}, {-2, 2}};
        std::vector<std::vector<int>> expected{{-2, 2}};
        auto ret = kClosest(points, 1);
        check(ret, expected);
    }
    {
        std::vector<std::vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};
        std::vector<std::vector<int>> expected{{3, 3}, {-2, 4}};
        auto ret = kClosest(points, 2);
        check(ret, expected);
    }
    return 0;
}
