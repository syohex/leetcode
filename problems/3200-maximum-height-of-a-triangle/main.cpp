#include <cassert>
#include <algorithm>

int maxHeightOfTriangle(int red, int blue) {
    const auto f = [](int first, int second) {
        bool is_odd = true;
        int num = 1;
        int rows = 0;
        while (true) {
            if (is_odd) {
                if (first >= num) {
                    first -= num;
                } else {
                    break;
                }
            } else {
                if (second >= num) {
                    second -= num;
                } else {
                    break;
                }
            }

            is_odd = !is_odd;
            ++num;
            ++rows;
        }

        return rows;
    };

    return std::max(f(red, blue), f(blue, red));
}

int main() {
    assert(maxHeightOfTriangle(2, 4) == 3);
    assert(maxHeightOfTriangle(2, 1) == 2);
    assert(maxHeightOfTriangle(1, 1) == 1);
    assert(maxHeightOfTriangle(10, 1) == 2);
    return 0;
}
