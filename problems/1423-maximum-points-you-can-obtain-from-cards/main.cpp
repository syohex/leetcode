#include <cassert>
#include <vector>
#include <algorithm>

int maxScore(const std::vector<int> &cardPoints, int k) {
    int sum = 0;
    int end = cardPoints.size() - 1;
    for (int i = 0; i < k; ++i) {
        sum += cardPoints[end - i];
    }

    int ret = sum;
    for (int i = 0; i < k; ++i) {
        sum += cardPoints[i];
        sum -= cardPoints[end - k + i + 1];
        ret = std::max(ret, sum);
    }

    return ret;
}

int main() {
    assert((maxScore(std::vector<int>{1, 2, 3, 4, 5, 6, 1}, 3) == 12));
    assert((maxScore(std::vector<int>{2, 2, 2}, 2) == 4));
    assert((maxScore(std::vector<int>{9, 7, 7, 9, 7, 7, 9}, 7) == 55));
    assert((maxScore(std::vector<int>{1, 1000, 1}, 1) == 1));
    assert((maxScore(std::vector<int>{1, 79, 80, 1, 1, 1, 200, 1}, 3) == 202));
    return 0;
}
