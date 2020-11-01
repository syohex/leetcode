#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

bool canAttendMeetings(std::vector<std::vector<int>> &intervals) {
    if (intervals.size() <= 1) {
        return true;
    }

    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });

    for (size_t i = 0; i < intervals.size() - 1; ++i) {
        if (intervals[i][1] > intervals[i + 1][0]) {
            return false;
        }
    }
    return true;
}

int main() {
    {
        std::vector<std::vector<int>> intervals{
            {0, 30},
            {5, 10},
            {15, 20},
        };
        assert(!canAttendMeetings(intervals));
    }
    {
        std::vector<std::vector<int>> intervals{
            {7, 10},
            {2, 4},
        };
        assert(canAttendMeetings(intervals));
    }
    {
        std::vector<std::vector<int>> intervals{
            {1, 5},
            {8, 9},
        };
        assert(canAttendMeetings(intervals));
    }
    return 0;
}
