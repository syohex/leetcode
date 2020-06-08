#include <cassert>
#include <vector>
#include <algorithm>

int lastStoneWeight(std::vector<int> &stones) {
    while (stones.size() >= 2) {
        std::sort(stones.begin(), stones.end());

        int a = stones[stones.size() - 1];
        int b = stones[stones.size() - 2];
        stones.resize(stones.size() - 2);
        int c;
        if (a == b) {
            if (stones.size() <= 1) {
                stones.push_back(0);
            }
            continue;
        } else if (a < b) {
            c = b - a;
        } else {
            c = a - b;
        }

        stones.push_back(c);
    }

    return stones[0];
}

int main() {
    {
        std::vector<int> input{2, 7, 4, 1, 8, 1};
        assert(lastStoneWeight(input) == 1);
    }
    {
        std::vector<int> input{9};
        assert(lastStoneWeight(input) == 9);
    }
    {
        std::vector<int> input{2, 2};
        assert(lastStoneWeight(input) == 0);
    }
    {
        std::vector<int> input{1, 2, 2};
        assert(lastStoneWeight(input) == 1);
    }
}
