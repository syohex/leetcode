#include <cassert>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> minOperations(const std::string &boxes) {
    int len = boxes.size();
    std::vector<int> v;
    for (int i = 0; i < len; ++i) {
        if (boxes[i] == '1') {
            v.push_back(i);
        }
    }

    std::vector<int> ret;
    for (int i = 0; i < len; ++i) {
        int sum = 0;
        for (int j : v) {
            sum += std::abs(i - j);
        }

        ret.push_back(sum);
    }

    return ret;
}

int main() {
    assert((minOperations("110") == std::vector<int>{1, 1, 3}));
    assert((minOperations("001011") == std::vector<int>{11, 8, 5, 4, 3, 4}));
    return 0;
}
