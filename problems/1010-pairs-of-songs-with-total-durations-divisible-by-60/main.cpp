#include <cassert>
#include <vector>

int numPairsDivisibleBy60(const std::vector<int> &time) {
    int ret = 0;
    for (size_t i = 0; i < time.size() - 1; ++i) {
        for (size_t j = i + 1; j < time.size(); ++j) {
            if ((time[i] + time[j]) % 60 == 0) {
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{30, 20, 150, 100, 40};
        assert(numPairsDivisibleBy60(input) == 3);
    }
    {
        std::vector<int> input{60, 60, 60};
        assert(numPairsDivisibleBy60(input) == 3);
    }
    return 0;
}
