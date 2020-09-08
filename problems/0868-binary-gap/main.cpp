#include <cassert>
#include <vector>
#include <cstdio>

int binaryGap(int N) {
    std::vector<int> v;

    while (true) {
        v.push_back(N % 2);
        N /= 2;
        if (N == 0) {
            break;
        }
    }

    printf("[");
    for (auto i : v) {
        printf(" %d ", i);
    }
    printf("]\n");

    auto it = v.begin();
    for (; it != v.end(); ++it) {
        if (*it == 1) {
            break;
        }
    }

    int max = 0;
    int count = 0;
    int ones = 0;
    for (; it != v.end(); ++it) {
        if (*it == 0) {
            ++count;
        } else {
            ++ones;
            if (count > max) {
                max = count;
            }
            count = 0;
        }
    }

    if (ones == 1) {
        return 0;
    }

    return max + 1;
}

int main() {
    assert(binaryGap(22) == 2);
    assert(binaryGap(5) == 2);
    assert(binaryGap(6) == 1);
    assert(binaryGap(8) == 0);
    assert(binaryGap(343) == 2);
    return 0;
}
