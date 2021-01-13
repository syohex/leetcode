#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

int numRescueBoats(const std::vector<int> &people, int limit) {
    std::map<int, int> m;
    int min = INT_MAX;
    for (int p : people) {
        ++m[p];
        min = std::min(min, p);
    }

    int count = people.size();
    int saves = 0;
    int ret = 0;
    while (saves < count) {
        for (auto &it : m) {
            if (it.second == 0) {
                continue;
            }

            --it.second;
            ++saves;

            int diff = limit - it.first;
            for (int i = diff; i >= min; --i) {
                if (m[i] != 0) {
                    --m[i];
                    ++saves;
                    break;
                }
            }

            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2};
        assert(numRescueBoats(input, 3) == 1);
    }
    {
        std::vector<int> input{3, 2, 2, 1};
        assert(numRescueBoats(input, 3) == 3);
    }
    {
        std::vector<int> input{3, 5, 3, 4};
        assert(numRescueBoats(input, 5) == 4);
    }
    return 0;
}
