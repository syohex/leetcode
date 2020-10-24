#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int bagOfTokensScore(std::vector<int> &tokens, int P) {
    if (tokens.empty()) {
        return 0;
    }

    std::sort(tokens.begin(), tokens.end());
    int point = 0;
    int ret = 0;
    int low = 0, high = static_cast<int>(tokens.size() - 1);
    while (low <= high && (P >= tokens[low] || point > 0)) {
        while (low <= high && P >= tokens[low]) {
            ++point;
            P -= tokens[low];
            ++low;
        }

        ret = std::max(point, ret);

        if (low <= high && point > 0) {
            --point;
            P += tokens[high];
            --high;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{100};
        assert(bagOfTokensScore(input, 50) == 0);
    }
    {
        std::vector<int> input{100, 200};
        assert(bagOfTokensScore(input, 150) == 1);
    }
    {
        std::vector<int> input{100, 200, 300, 400};
        assert(bagOfTokensScore(input, 200) == 2);
    }
    {
        std::vector<int> input{26};
        assert(bagOfTokensScore(input, 51) == 1);
    }
    {
        std::vector<int> input{71, 55, 82};
        assert(bagOfTokensScore(input, 54) == 0);
    }
    return 0;
}
