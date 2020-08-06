#include <cassert>
#include <vector>
#include <set>

int numPairsDivisibleBy60(const std::vector<int> &time) {
    std::set<int> cache;
    int ret = 0;
    for (size_t i = 0; i < time.size() - 1; ++i) {
        if (cache.find(time[i]) != cache.end()) {
            continue;
        }

        int dups = 1;
        int count = 0;
        for (size_t j = i + 1; j < time.size(); ++j) {
            if ((time[i] + time[j]) % 60 == 0) {
                count += dups;
            }

            if (time[i] == time[j]) {
                ++dups;
            }
        }

        cache.insert(time[i]);
        ret += count;
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
    {
        std::vector<int> input{440, 204, 481, 140, 310, 354, 34, 150, 184, 360, 16, 301, 290, 178, 138, 393, 399, 260, 381, 499};
        assert(numPairsDivisibleBy60(input) == 2);
    }
    {
        std::vector<int> input{269, 230, 318, 468, 171, 158, 350, 60,  287, 27,  11,  384, 332, 267, 412, 478, 280, 303,
                               242, 378, 129, 131, 164, 467, 345, 146, 264, 332, 276, 479, 284, 433, 117, 197, 430, 203,
                               100, 280, 145, 287, 91,  157, 5,   475, 288, 146, 370, 199, 81,  428, 278, 2,   400, 23,
                               470, 242, 411, 470, 330, 144, 189, 204, 62,  318, 475, 24,  457, 83,  204, 322, 250, 478,
                               186, 467, 350, 171, 119, 245, 399, 112, 252, 201, 324, 317, 293, 44,  295, 14,  379, 382,
                               137, 280, 265, 78,  38,  323, 347, 499, 238, 110, 18,  224, 473, 289, 198, 106, 256, 279,
                               275, 349, 210, 498, 201, 175, 472, 461, 116, 144, 9,   221, 473};
        assert(numPairsDivisibleBy60(input) == 105);
    }
    return 0;
}
