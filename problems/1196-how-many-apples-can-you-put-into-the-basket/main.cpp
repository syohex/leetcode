#include <cassert>
#include <vector>
#include <algorithm>

int maxNumberOfApples(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    if (arr[0] > 5000) {
        return 0;
    }

    int i;
    int sum = 0;
    for (i = 0; i < static_cast<int>(arr.size()); ++i) {
        sum += arr[i];
        if (sum > 5000) {
            return i;
        }
    }

    return i;
}

int main() {
    {
        std::vector<int> input{100, 200, 150, 1000};
        assert(maxNumberOfApples(input) == 4);
    }
    {
        std::vector<int> input{900, 950, 800, 1000, 700, 800};
        assert(maxNumberOfApples(input) == 5);
    }
    return 0;
}
