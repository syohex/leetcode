#include <cassert>
#include <vector>
#include <algorithm>

int maxScore(const std::vector<int> &cardPoints, int k) {
    int sum = 0;
    int len = cardPoints.size();
    for (int i = 1; i <= k; ++i) {
        sum += cardPoints[len - i];
    }

    int ret = sum;
    for (int i = 0; i < k; ++i) {
        sum = sum + cardPoints[i] - cardPoints[len - k + i];
        ret = std::max(ret, sum);
    }

    return ret;
}

int main() {
    {
        std::vector<int> cardPoints{1, 2, 3, 4, 5, 6, 1};
        int ret = maxScore(cardPoints, 3);
        assert(ret == 12);
    }
    {
        std::vector<int> cardPoints{2, 2, 2};
        int ret = maxScore(cardPoints, 2);
        assert(ret == 4);
    }
    {
        std::vector<int> cardPoints{9, 7, 7, 9, 7, 7, 9};
        int ret = maxScore(cardPoints, 7);
        assert(ret == 55);
    }
    {
        std::vector<int> cardPoints{100, 40, 17, 9, 73, 75};
        int ret = maxScore(cardPoints, 3);
        assert(ret == 248);
    }
    return 0;
}
