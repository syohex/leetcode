#include <cassert>
#include <vector>

int busyStudent(const std::vector<int> &startTime, const std::vector<int> &endTime, int queryTime) {
    int ret = 0;
    for (size_t i = 0; i < startTime.size(); ++i) {
        if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> start{1, 2, 3};
        std::vector<int> end{3, 2, 7};
        assert(busyStudent(start, end, 4) == 1);
    }
    {
        std::vector<int> start{4};
        std::vector<int> end{4};
        assert(busyStudent(start, end, 4) == 1);
    }
    {
        std::vector<int> start{1, 1, 1, 1};
        std::vector<int> end{1, 3, 2, 4};
        assert(busyStudent(start, end, 7) == 0);
    }
    {
        std::vector<int> start{9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::vector<int> end{10, 10, 10, 10, 10, 10, 10, 10, 10};
        assert(busyStudent(start, end, 5) == 5);
    }
    return 0;
}
