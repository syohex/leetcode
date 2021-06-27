#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int candy(const std::vector<int> &ratings) {
    int len = ratings.size();
    std::vector<int> v1(len, 1);

    for (int i = 1; i < len; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            v1[i] = v1[i - 1] + 1;
        }
    }

    std::vector<int> v2(len, 1);
    for (int i = len - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            v2[i] = v2[i + 1] + 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < len; ++i) {
        ret += std::max(v1[i], v2[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> ratings{1, 0, 2};
        assert(candy(ratings) == 5);
    }
    {
        std::vector<int> ratings{1, 2, 2};
        assert(candy(ratings) == 4);
    }
    return 0;
}
