#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>

int minMovesToSeat(std::vector<int> &seats, std::vector<int> &students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());

    int ret = 0;
    for (size_t i = 0; i < seats.size(); ++i) {
        ret += std::abs(seats[i] - students[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> seats{3, 1, 5};
        std::vector<int> students{2, 7, 4};
        assert(minMovesToSeat(seats, students) == 4);
    }
    {
        std::vector<int> seats{4, 1, 5, 9};
        std::vector<int> students{1, 3, 2, 6};
        assert(minMovesToSeat(seats, students) == 7);
    }
    {
        std::vector<int> seats{2, 2, 6, 6};
        std::vector<int> students{1, 3, 2, 6};
        assert(minMovesToSeat(seats, students) == 4);
    }
    return 0;
}
