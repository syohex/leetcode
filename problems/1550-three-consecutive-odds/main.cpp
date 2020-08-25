#include <cassert>
#include <vector>

bool threeConsecutiveOdds(const std::vector<int> &arr) {
    int count = 0;
    for (const int a : arr) {
        if (a % 2 != 0) {
            ++count;
            if (count == 3) {
                return true;
            }
            continue;
        }

        count = 0;
    }
    return false;
}

int main() {
    {
        std::vector<int> input{2, 6, 4, 1};
        assert(!threeConsecutiveOdds(input));
    }
    {
        std::vector<int> input{1, 2, 34, 3, 4, 5, 7, 23, 12};
        assert(threeConsecutiveOdds(input));
    }
    return 0;
}
