#include <cassert>
#include <vector>

bool isRectangleOverlap(const std::vector<int> &rec1, const std::vector<int> &rec2) {
    if (rec1[0] >= rec2[2] || rec2[0] >= rec1[2]) {
        return false;
    }

    if (rec1[1] >= rec2[3] || rec2[1] >= rec1[3]) {
        return false;
    }
    return true;
}

int main() {
    {
        std::vector<int> v1{0, 0, 2, 2};
        std::vector<int> v2{1, 1, 3, 3};
        assert(isRectangleOverlap(v1, v2));
    }
    {
        std::vector<int> v1{0, 0, 1, 1};
        std::vector<int> v2{1, 0, 2, 1};
        assert(!isRectangleOverlap(v1, v2));
    }
    return 0;
}
