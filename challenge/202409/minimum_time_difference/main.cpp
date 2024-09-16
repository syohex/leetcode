#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int findMinDifference(const std::vector<std::string> &timePoints) {
    std::vector<int> v;
    for (const auto &t : timePoints) {
        int mins = (((t[0] - '0') * 10 + t[1] - '0') * 60) + (t[3] - '0') * 10 + t[4] - '0';
        v.push_back(mins);
    }

    std::sort(v.begin(), v.end());
    v.push_back(v[0] + 1440);

    int len = v.size();
    int ret = 2000;
    for (int i = 1; i < len; ++i) {
        ret = std::min(ret, v[i] - v[i - 1]);
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> timePoints{"23:59", "00:00"};
        int ret = findMinDifference(timePoints);
        assert(ret == 1);
    }
    {
        std::vector<std::string> timePoints{"00:00", "23:59", "00:00"};
        int ret = findMinDifference(timePoints);
        assert(ret == 0);
    }
    return 0;
}
