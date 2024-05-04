#include <cassert>
#include <vector>
#include <algorithm>

int numRescueBoats(std::vector<int> &people, int limit) {
    std::sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;

    int ret = 0;
    while (left <= right) {
        ret += 1;

        if (people[left] + people[right] <= limit) {
            ++left;
        }

        --right;
    }

    return ret;
}

int main() {
    {
        std::vector<int> people{1, 2};
        int ret = numRescueBoats(people, 3);
        assert(ret == 1);
    }
    {
        std::vector<int> people{3, 2, 2, 1};
        int ret = numRescueBoats(people, 3);
        assert(ret == 3);
    }
    {
        std::vector<int> people{3, 5, 3, 4};
        int ret = numRescueBoats(people, 5);
        assert(ret == 4);
    }
    return 0;
}
