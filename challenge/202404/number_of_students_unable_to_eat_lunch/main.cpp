#include <cassert>
#include <vector>
#include <cstdio>

int countStudents(const std::vector<int> &students, const std::vector<int> &sandwiches) {
    int ones = 0;
    int zeros = 0;
    for (int s : students) {
        if (s == 1) {
            ++ones;
        } else {
            ++zeros;
        }
    }

    for (int s : sandwiches) {
        if (s == 0 && zeros > 0) {
            --zeros;
            continue;
        }
        if (s == 1 && ones > 0) {
            --ones;
            continue;
        }

        break;
    }

    return ones + zeros;
}

int main() {
    {
        std::vector<int> students{1, 1, 0, 0};
        std::vector<int> sandwiches{0, 1, 0, 1};
        int ret = countStudents(students, sandwiches);
        assert(ret == 0);
    }
    {
        std::vector<int> students{1, 1, 1, 0, 0, 1};
        std::vector<int> sandwiches{1, 0, 0, 0, 1, 1};
        int ret = countStudents(students, sandwiches);
        assert(ret == 3);
    }
    return 0;
}
