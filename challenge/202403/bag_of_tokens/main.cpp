#include <cassert>
#include <vector>
#include <algorithm>

int bagOfTokensScore(std::vector<int> &tokens, int power) {
    std::sort(tokens.begin(), tokens.end());

    int score = 0;
    int ret = 0;

    int left = 0;
    int right = tokens.size() - 1;

    while (left <= right) {
        if (power >= tokens[left]) {
            score += 1;
            power -= tokens[left];
            ++left;
        } else if (score >= 1) {
            score -= 1;
            power += tokens[right];
            --right;
        } else {
            break;
        }

        ret = std::max(ret, score);
    }

    return ret;
}

int main() {
    {
        std::vector<int> tokens{100};
        int ret = bagOfTokensScore(tokens, 50);
        assert(ret == 0);
    }
    {
        std::vector<int> tokens{200, 100};
        int ret = bagOfTokensScore(tokens, 150);
        assert(ret == 1);
    }
    {
        std::vector<int> tokens{100, 200, 300, 400};
        int ret = bagOfTokensScore(tokens, 200);
        assert(ret == 2);
    }
    {
        std::vector<int> tokens{26};
        int ret = bagOfTokensScore(tokens, 51);
        assert(ret == 1);
    }
    {
        std::vector<int> tokens{25,91};
        int ret = bagOfTokensScore(tokens, 99);
        assert(ret == 1);
    }
    return 0;
}
