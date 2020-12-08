#include <cassert>
#include <vector>
#include <set>

int numPairsDivisibleBy60(const std::vector<int> &time) {
    std::set<int> counted;

    int ret = 0;
    for (size_t i = 0; i < time.size() - 1; ++i) {
        if (counted.find(time[i]) != counted.end()) {
            continue;
        }

        int target = 1;
        for (size_t j = i + 1; j < time.size(); ++j) {
            if ((time[i] + time[j]) % 60 == 0) {
                ret += target;
            }

            if (time[i] == time[j]) {
                ++target;
            }
        }

        counted.insert(time[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> time{30, 20, 150, 100, 40};
        assert(numPairsDivisibleBy60(time) == 3);
    }
    {
        std::vector<int> time{60, 60, 60};
        assert(numPairsDivisibleBy60(time) == 3);
    }
    return 0;
}
