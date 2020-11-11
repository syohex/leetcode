#include <cassert>
#include <vector>
#include <cmath>

bool validSquare(const std::vector<int> &p1, const std::vector<int> &p2, const std::vector<int> &p3, const std::vector<int> &p4) {
    const auto distance = [](const std::vector<int> &p1, const std::vector<int> &p2) -> int {
        return std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2);
    };

    int d1 = distance(p1, p2);
    int d2 = distance(p1, p3);
    int d3 = distance(p1, p4);
    if (d1 == 0 || d2 == 0 || d3 == 0) {
        return false;
    }

    if (d1 == d2 && (d1 + d2) == d3 && (distance(p2, p4) + distance(p3, p4)) == distance(p2, p3)) {
        return true;
    }
    if (d2 == d3 && (d2 + d3) == d1 && (distance(p3, p2) + distance(p4, p2)) == distance(p3, p4)) {
        return true;
    }
    if (d3 == d1 && (d3 + d1) == d2 && (distance(p2, p3) + distance(p4, p3)) == distance(p2, p4)) {
        return true;
    }

    return false;
}

int main() {
    {
        std::vector<int> p1{0, 0};
        std::vector<int> p2{1, 1};
        std::vector<int> p3{1, 0};
        std::vector<int> p4{0, 1};
        assert(validSquare(p1, p2, p3, p4));
    }
    {
        std::vector<int> p1{1, 0};
        std::vector<int> p2{-1, 0};
        std::vector<int> p3{0, 1};
        std::vector<int> p4{0, -1};
        assert(validSquare(p1, p2, p3, p4));
    }
    {
        std::vector<int> p1{0, 1};
        std::vector<int> p2{1, 2};
        std::vector<int> p3{0, 2};
        std::vector<int> p4{0, 0};
        assert(!validSquare(p1, p2, p3, p4));
    }
    {
        std::vector<int> p1{1, 1};
        std::vector<int> p2{0, 1};
        std::vector<int> p3{1, 2};
        std::vector<int> p4{0, 0};
        assert(!validSquare(p1, p2, p3, p4));
    }
    return 0;
}
