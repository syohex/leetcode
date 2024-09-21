#include <cassert>
#include <vector>

std::vector<int> lexicalOrder(int n) {
    std::vector<int> ret;
    int v = 1;
    for (int i = 1; i <= n; ++i) {
        ret.push_back(v);

        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 == 9 || v >= n) {
                v /= 10;
            }

            v += 1;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> expected{1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
        auto ret = lexicalOrder(13);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{1, 2};
        auto ret = lexicalOrder(2);
        assert(ret == expected);
    }
    return 0;
}
