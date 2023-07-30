#include <cassert>
#include <vector>

int numberOfEmployeesWhoMetTarget(const std::vector<int> &hours, int target) {
    int ret = 0;
    for (int hour : hours) {
        if (hour >= target) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> hours{0, 1, 2, 3, 4};
        int ret = numberOfEmployeesWhoMetTarget(hours, 2);
        assert(ret == 3);
    }
    {
        std::vector<int> hours{5, 1, 4, 2, 2};
        int ret = numberOfEmployeesWhoMetTarget(hours, 6);
        assert(ret == 0);
    }
    return 0;
}
