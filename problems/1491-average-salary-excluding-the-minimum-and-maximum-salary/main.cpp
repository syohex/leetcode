#include <cassert>
#include <vector>
#include <climits>
#include <cstdio>

double average(std::vector<int> &salary) {
    int sum = 0;
    int min = INT_MAX, max = INT_MIN;
    for (int s : salary) {
        sum += s;
        if (s < min) {
            min = s;
        }
        if (s > max) {
            max = s;
        }
    }

    return (sum - min - max) / static_cast<double>(salary.size() - 2);
}

int main() {
    {
        std::vector<int> input{4000, 3000, 1000, 2000};
        assert(average(input) == 2500);
    }
    {
        std::vector<int> input{1000, 2000, 3000};
        assert(average(input) == 2000);
    }
    {
        std::vector<int> input{6000, 5000, 4000, 3000, 2000, 1000};
        assert(average(input) == 3500);
    }
    {
        std::vector<int> input{8000, 9000, 2000, 3000, 6000, 1000};
        assert(average(input) == 4750);
    }
    return 0;
}
